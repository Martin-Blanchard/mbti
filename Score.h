#ifndef SCORE_H
#define SCORE_H

class Score
{
public:
    Score();
    void ajout_score(char lettre,int score);
    int get_score(char lettre) const;
    char get_inv(char lettre) const;
    void get_percentage(int& percent_e, int& percent_i, int& percent_n, int& percent_s, int &percent_t, int& percent_f, int& percent_j, int& percent_p) const;

private:
    unsigned int *m_score_e;
    unsigned int *m_score_i;
    unsigned int *m_score_n;
    unsigned int *m_score_s;
    unsigned int *m_score_f;
    unsigned int *m_score_t;
    unsigned int *m_score_j;
    unsigned int *m_score_p;
};

#endif // SCORE_H
