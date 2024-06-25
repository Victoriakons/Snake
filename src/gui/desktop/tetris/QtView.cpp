#include "QtView.h"
#include "mainwindow.h"
#include "brick_game/tetris/s21_backend.h"
#include <QLabel>
#include <curses.h>
#include <QThread>


using namespace std;


//int x = WIDTH/2;
//int y = HEIGHT/2;
//COORD coord = {x, y};
//Model::Snake snake(coord, 1);
//Model::Food food;

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
    Block block;
    if(m_isGameOver) {
        painter.setFont(QFont("Arial", 10, 700));
        painter.drawText(QRect(0,0,width(),height()), Qt::AlignCenter, "ИГРА ПРОИГРАНА\nсчет : " + QString::number(m_score));
        return;
    }
    painter.drawRect(0,0,width()-1,height()-1);
    //отрисовка
    display_piece(block);

    }


    // Check if the piece is valid

//     //отрисовка еды
//    painter.drawEllipse(food.get_pos().X * 10, food.get_pos().Y * 10, 10, 10);

//    painter.end();
//    m_isMoveBlocked = false;

//}

//void GameField::MoveSnakeSlot()
//{
//    m_snake->move_snake();
//    repaint();


//    if(m_snake->collided()) {
//        GameOver();
//    }

//    //получение еды
//    if(m_snake->eaten(food.get_pos())) {
//       food.gen_food();
//       m_snake->grow();
//       m_score ++;
//       QString text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
//       emit ChangeTextSignals(text);
//}
//}




void GameField::keyPressEvent(QKeyEvent *e)
{
//    if(e->key() == Qt::Key_Space) {
//        if(m_isGameOver) {
//            StartNewGame();
//            return;
//        }
//        m_isPause = !m_isPause;
//        SetGameStatus();
//        }

//    if(m_isMoveBlocked){
//        return; //если смена направлений запрещена выходим из функции
//    }

//    if(e->key() == Qt::Key_Left && m_snake->direction != 'r') {
//        m_snake->direction = 'l';
//    }

//    if(e->key() == Qt::Key_Right && m_snake->direction != 'l') {
//        m_snake->direction = 'r';
//    }

//    if(e->key() == Qt::Key_Up && m_snake->direction != 'd') {
//        m_snake->direction = 'u';
//    }

//    if(e->key() == Qt::Key_Down && m_snake->direction != 'u') {
//        m_snake->direction = 'd';
//    }
//    m_isMoveBlocked = true;
}



void GameField::SetGameStatus()
{
//    QString text;
//    if(m_isPause) {
//        m_moveSnakeTimer->stop();
//        text = "счет : " + QString::number(m_score) + "\nпродолжить - ПРОБЕЛ";
//    } else {
//        m_moveSnakeTimer->start(100);
//        text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
//    }
//    emit ChangeTextSignals(text);
    }


void GameField::GameOver()
{
//    m_isGameOver = true;
//    QString text = "начать заново - ПРОБЕЛ";
//    emit ChangeTextSignals(text);
//    m_moveSnakeTimer->stop();
//    delete m_snake;
//    delete m_moveSnakeTimer;
}

void GameField::StartNewGame()
{
//    m_isPause = false;

//    m_isMoveBlocked = false;

//    m_isGameOver = false;

//    m_snake = new Model::Snake(coord,1);

//    m_moveSnakeTimer = new QTimer();

//    connect(m_moveSnakeTimer, &QTimer::timeout, this, &GameField::MoveSnakeSlot);
//    m_moveSnakeTimer->start(100);

//    m_score = 0;
//    QString text = "счет : " + QString::number(m_score) + "\nпауза - ПРОБЕЛ";
//    emit ChangeTextSignals(text);

}

