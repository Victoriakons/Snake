#ifndef MAINQT_H
#define MAINQT_H


#include <QWidget>
#include <QPainter>
#include "model.h"
//#include <QList>
#include <QTimer>
#include <QKeyEvent>
//#include <QRandomGenerator>
#include <QGraphicsScene>




class GameField : public QWidget
{
    friend Snake;
    Q_OBJECT
public:
    GameField();

protected:
    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

private:
    Snake *m_snake;
//    int m_snakeItemSize;
    Food food;
    QTimer *m_moveSnakeTimer;
    int m_fieldSize;
    int m_score;
    bool m_isPause;
    bool m_isMoveBlocked;
    bool m_isGameOver;
    void SetGameStatus();
    void GameOver();
    void StartNewGame();

private slots:
    void MoveSnakeSlot();

signals:
    void ChangeTextSignals(QString text);
};

#endif // MAINQT_H
