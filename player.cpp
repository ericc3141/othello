#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     s = side;
     board = Board();
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    Side other = (s == BLACK) ? WHITE : BLACK;
    board.doMove(opponentsMove, other);
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    std::cerr << s << std::endl;
    Move *move = new Move(0,0);
    for (int x = 0; x < 8; x ++) {
        for (int y = 0; y < 8; y ++) {
            move->setX(x);
            move->setY(y);
            if (board.checkMove(move, s)){
                std::cerr << x << y << std::endl;
                //move->setX(x+1);
                //move->setY(y+1);
                board.doMove(move, s);
                return move;
            }
        }
    }
    std::cerr << "hi" << std::endl;
    return nullptr;
}
