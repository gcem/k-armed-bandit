class BanditSolver
{
public:
    /**
     * @brief Construct a new Bandit Solver object
     *
     * @param arms Number of arms of bandit
     */
    BanditSolver(int arms);

    /**
     * @brief Gets the next choice of solver
     *
     * @return a number in range [0, arms - 1]
     */
    virtual int getChoice() = 0;

    /**
     * @brief Set the reward received due to the last choice from getChoice()
     *
     * @param reward Reward due to last choice, can be negative
     */
    virtual void setReward(double reward) = 0;

protected:
    int arms;
};