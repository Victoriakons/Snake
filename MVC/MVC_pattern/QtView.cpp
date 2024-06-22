#include "QtView.h"
#include "model.h"
#include "mainwindow.h"
#include <QLabel>
#include <curses.h>
#include <QThread>


using namespace std;


int x = WIDTH/2;
int y = HEIGHT/2;
COORD coord = {x, y};
Snake snake(coord, 1);
Food food;




//int main()
//{
//    score = 0;
//    srand(time(NULL));
//    initscr();
//    noecho();
//    curs_set(0);

//    bool game_over = false;
//    while(!game_over){
//        board();
//        refresh();
//        keypad(stdscr, TRUE);
//        mvprintw(HEIGHT+1, 0, "SCORE : %d", score);
//        refresh();
//        int ch = getch();

//        switch(ch)
//            {
//                // case 132:
//                case KEY_UP:
//                snake.change_dir('u');
//                break;

//                case KEY_DOWN:
//                snake.change_dir('d');
//                break;

//                case KEY_LEFT:
//                snake.change_dir('l');
//                break;

//                case KEY_RIGHT:
//                snake.change_dir('r');
//                break;


//            }
            

//            if(snake.eaten(food.get_pos())) {
//                food.gen_food();
//                snake.grow();
//                score++;
//            }
//            if(snake.collided()) game_over = true;

//            snake.move_snake();

//            refresh();
            
//        }
//    endwin();
//    return 0;
//}




GameField::GameField()
{
    setFixedSize(220,300);
    setFocusPolicy(Qt::StrongFocus);
    m_fieldSize = width() / 10;
    StartNewGame();

}

void GameField::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter;
    painter.begin(this);
    if(m_isGameOver) {
        painter.setFont(QFont("Arial", 10, 700));
        painter.drawText(QRect(0,0,width(),height()), Qt::AlignCenter, "ИГРА ПРОИГРАНА\nсчет : " + QString::number(m_score));
        return;
    }
    painter.drawRect(0,0,width()-1,height()-1);
    //отрисовка змейки
    for(unsigned long i = 0; i < m_snake->len; i++) {
        painter.drawEllipse(m_snake->body[i].X * 10, m_snake->body[i].Y * 10, 10, 10);

    }

     //отрисовка еды
    painter.drawEllipse(food.get_pos().X * 10, food.get_pos().Y * 10, 10, 10);

    painter.end();
    m_isMoveBlocked = false;

}

void GameField::MoveSnakeSlot()
{
    m_snake->move_snake();
    repaint();


    if(m_snake->collided()) {
        GameOver();
    }

    //получение еды
    if(m_snake->eaten(food.get_pos())) {
       food.gen_food();
       m_snake->grow();
       m_score ++;
       QString text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
       emit ChangeTextSignals(text);
}
}




void GameField::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Space) {
        if(m_isGameOver) {
            StartNewGame();
            return;
        }
        m_isPause = !m_isPause;
        SetGameStatus();
        }

    if(m_isMoveBlocked){
        return; //если смена направлений запрещена выходим из функции
    }

    if(e->key() == Qt::Key_Left && m_snake->direction != 'r') {
        m_snake->direction = 'l';
    }

    if(e->key() == Qt::Key_Right && m_snake->direction != 'l') {
        m_snake->direction = 'r';
    }

    if(e->key() == Qt::Key_Up && m_snake->direction != 'd') {
        m_snake->direction = 'u';
    }

    if(e->key() == Qt::Key_Down && m_snake->direction != 'u') {
        m_snake->direction = 'd';
    }
    m_isMoveBlocked = true;
}



void GameField::SetGameStatus()
{
    QString text;
    if(m_isPause) {
        m_moveSnakeTimer->stop();
        text = "счет : " + QString::number(m_score) + "\nпродолжить - ПРОБЕЛ";
    } else {
        m_moveSnakeTimer->start(100);
        text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
    }
    emit ChangeTextSignals(text);
    }


void GameField::GameOver()
{
    m_isGameOver = true;
    QString text = "начать заново - ПРОБЕЛ";
    emit ChangeTextSignals(text);
    m_moveSnakeTimer->stop();
    delete m_snake;
    delete m_moveSnakeTimer;
}

void GameField::StartNewGame()
{
    m_isPause = false;

    m_isMoveBlocked = false;

    m_isGameOver = false;

    m_snake = new Snake(coord,1);

    m_moveSnakeTimer = new QTimer();

    connect(m_moveSnakeTimer, &QTimer::timeout, this, &GameField::MoveSnakeSlot);
    m_moveSnakeTimer->start(100);

    m_score = 0;
    QString text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
    emit ChangeTextSignals(text);

}

