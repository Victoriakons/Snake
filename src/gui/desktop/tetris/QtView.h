#ifndef MAINQT_H
#define MAINQT_H


#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
//#include <QRandomGenerator>
#include <QGraphicsScene>
#include "brick_game/tetris/s21_backend.h"


#define COLS_PER_CELL 2

class GameField : public QWidget
{
//    friend Model;
    Q_OBJECT
public:
    GameField();

protected:
    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;


private:
//    Model::Snake *m_snake;
////    int m_snakeItemSize;
//    Model::Food food;
//    QTimer *m_moveSnakeTimer;
    int m_fieldSize;
    int m_score;
//    bool m_isPause;
//    bool m_isMoveBlocked;
    bool m_isGameOver;
    void SetGameStatus();
    void GameOver();
    void StartNewGame();
    void display_piece(Block block) ;


//private slots:
//    void MoveSnakeSlot();

signals:
    void ChangeTextSignals(QString text);
};

#endif // MAINQT_H
