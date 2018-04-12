#ifndef ENTERSEARCHBOARD_H
#define ENTERSEARCHBOARD_H

#include "viewController/chessboard.h"

class EnterSearchBoard : public Chessboard
{
    Q_OBJECT

public:
    explicit EnterSearchBoard(ColorStyle *style, chess::Board *board, QWidget *parent = 0);
    void setToInitialPosition();
    void setToCurrentBoard();
    void clearBoard();
    chess::Board *getCurrentBoard();

private:
    bool clickedOnBoard(int x, int y);
    bool clickedOnPiceceSelector(int x, int y);
    // get selected piece for mouse coordinates
    // mouse coordinates must be on piece selector
    uint8_t getSelectedPiece(int x, int y);
    // get board position for mouse coordinates
    // board position is tuple (i,j) where i is x-axis from 0 to 7
    // and y is y-axis
    QPoint getBoardPosition(int x, int y);

    chess::Board *currentGameBoard;
    void drawBoard(QPaintEvent *e, QPainter *q);
    //void calculateBoardSize(int *boardSize, int *squareSize);
    void resizeTo(float ratio);

    uint8_t pickupPieces[7][2] =  {{chess::WHITE_PAWN, chess::BLACK_PAWN},
                                   {chess::WHITE_KNIGHT, chess::BLACK_KNIGHT},
                                   {chess::WHITE_BISHOP, chess::BLACK_BISHOP},
                                   {chess::WHITE_ROOK, chess::BLACK_ROOK},
                                   {chess::WHITE_QUEEN, chess::BLACK_QUEEN},
                                   {chess::WHITE_KING, chess::BLACK_KING},
                                   {chess::WHITE_PIECE, chess::BLACK_PIECE}};

    uint8_t selectedPiece;

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *m);

signals:
    void squareChanged();

public slots:


};

#endif // ENTERSEARCHBOARD_H