#ifndef USERTYPE_H
#define USERTYPE_H
class userType
{
public:
    void go(int = 0);
    void callSelectOp() const;
    void setSelection(int);
    void update(int, int, int);
    char getSelection() const;
    void updateGameData(int);
    void statHandlerIn(int, int, int, int, int, int);
    void statHandlerOut();
    void printStats();
    void reset(int = 0);
private:
    char selection;
    int wins;
    int losses;
    int totalGames;
    int total3Games;
    int total5Games;
    int total15Games;
};

#endif