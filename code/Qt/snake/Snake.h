#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
//http://zetcode.com/gui/qt5/snake/
class Snake : public QWidget {

  public:
      Snake(QWidget *parent = 0);

  protected:
      void paintEvent(QPaintEvent *);
      void timerEvent(QTimerEvent *);
      void keyPressEvent(QKeyEvent *);

  private:
      QImage dot;
      QImage head;
      QImage apple;

      static const int B_WIDTH = 300;
      static const int B_HEIGHT = 300;
      static const int DOT_SIZE = 10;
      static const int ALL_DOTS = 900;
      static const int RAND_POS = 29;
      static const int DELAY = 500; //140
/*The B_WIDTH and B_HEIGHT constants determine the size of the board.
 * The DOT_SIZE is the size of the apple and the dot of the snake. The
 * ALL_DOTS constant defines the maximum number of possible dots on the
 *  board (900 = (300*300)/(10*10)). The RAND_POS constant is used to
 *  calculate a random position for an apple. The DELAY constant determines
 * the speed of the game.*/
      int timerId;
      int dots;
      int apple_x;
      int apple_y;

      int x[ALL_DOTS];
      int y[ALL_DOTS];

      bool leftDirection;
      bool rightDirection;
      bool upDirection;
      bool downDirection;
      bool inGame;


      bool pause=false;

      void loadImages();
      void initGame();
      void locateApple();
      void checkApple();
      void checkCollision();
      void move();
      void doDrawing();
      void gameOver(QPainter &);
};

#endif // SNAKE_H
