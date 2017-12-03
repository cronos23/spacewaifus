#ifndef HIGHSCORES_HH
#define HIGHSCORES_HH

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <QWidget>
#include <vector>
#include "ioexception.hh"


namespace Ui {
class highscores;
}

/**
 * @brief A QWidget displaying the top 10 high scores read from a text file. Also responsible for updating
 * the text file if needed.
 */
class highscores : public QWidget
{
    Q_OBJECT

public:
    explicit highscores(QWidget *parent = 0);
    ~highscores();

    /**
     * @brief This utility function checks if the score given to it as a parameter is enough to reach the
     * top10.
     * @param The score parameter comes from statistics in their final state.
     * @return Returns true if param score can reach the top10, false if it can't.
     * @pre top10_ has been read from leaderboard.txt.
     */
    bool compareScoreToVector(unsigned int score);
    /**
     * @brief setter for name_ and score_.
     * @param The name parameter is saved into name_.
     * @param The score parameter is saved into score_.
     */
    void setNameandScore(std::string name, unsigned int score);
    /**
     * @brief Rewrites leaderboard.txt to add a new high score and remove the former bottom score.
     * @pre name_, score_ and top10_ all have proper values.
     * @post leaderboard.txt is rewritten and up to date.
     */
    void writeToFile();

private:
    Ui::highscores *ui;
    /**
     * @brief Holds the name the player has set in the ui.
     */
    std::string name_;
    /**
     * @brief Holds the players final score.
     */
    unsigned int score_;
    /**
     * @brief The playerScore struct holds the players inputted name and their final score. These are
     * used to keep the connection between name and score intact.
     */
    struct playerScore
    {
        std::string name;
        unsigned int score;
    };
    /**
     * @brief A comparator function used to sort vectors that hold playerScore structs.
     */
    static bool less_than_score(const highscores::playerScore & a, const highscores::playerScore & b);

    /**
     * @brief readFile reads information from leaderboard.txt, sorts it into playerScore structs and
     * pushes them into a vector.
     * @return The vector with 10 playerScore structs is returned.
     * @post Exception guarantee: strong. Throws IoException if leaderboard.txt is missing or doesn't have
     * exactly 10 rows.
     */
    std::vector<struct playerScore> readFile();
    /**
     * @brief Used to store the playerScore -vector created by readFile.
     */
    std::vector<struct playerScore> top10_;
};

#endif // HIGHSCORES_HH
