#include "Score.h"
#include <tgmath.h>

Score::Score()
{
    m_score_e = new unsigned int(0);
    m_score_i = new unsigned int(0);
    m_score_n = new unsigned int(0);
    m_score_s = new unsigned int(0);
    m_score_f = new unsigned int(0);
    m_score_t = new unsigned int(0);
    m_score_j = new unsigned int(0);
    m_score_p = new unsigned int(0);
}

void Score::ajout_score(char lettre, int score)
{
    switch(lettre)
    {
        case 'e':
            if(score >= 0)
            {
                *m_score_e = *m_score_e + score;
                break;
            }
            else
            {
                *m_score_i = *m_score_i - score;
                break;
            }
        case 'n':
            if(score >= 0)
            {
                *m_score_n = *m_score_n + score;
            }
            else
            {
                *m_score_s = *m_score_s - score;
            }
        case 't':
            if(score >= 0)
            {
                *m_score_t = *m_score_t + score;
            }
            else
            {
                *m_score_f = *m_score_f - score;
            }
        case 'j':
            if(score >= 0)
            {
                *m_score_j = *m_score_j + score;
            }
            else
            {
                *m_score_p = *m_score_p - score;
            }
    }
}

int Score::get_score(char lettre) const
{
    switch(lettre)
    {
        case 'e':
            return *m_score_e;
            break;
        case 'i':
            return *m_score_i;
            break;
        case 'n':
            return *m_score_n;
            break;
        case 's':
            return *m_score_s;
            break;
        case 't':
            return *m_score_t;
            break;
        case 'f':
            return *m_score_f;
            break;
        case 'j':
            return *m_score_j;
            break;
        case 'p':
            return *m_score_p;
            break;
        default:
            return 0;
    }
}

char Score::get_inv(char lettre) const
{
    switch(lettre)
    {
        case 'e':
            return 'i';
            break;
        case 'n':
            return 's';
            break;
        case 't':
            return 'f';
            break;
        case 'j':
            return 'p';
            break;
        default:
            return lettre;
    }
}

void Score::get_percentage(int& percent_e, int& percent_i, int& percent_n, int& percent_s, int &percent_t, int& percent_f, int& percent_j, int& percent_p) const
{
    if(*m_score_e == *m_score_i)
    {
        *m_score_i+=1;
    }
    percent_i = round(100* *m_score_i/(*m_score_e+*m_score_i));
    if(*m_score_n == *m_score_s)
    {
        *m_score_s+=1;
    }
    percent_s = round(100* *m_score_s/(*m_score_s+*m_score_n));
    if(*m_score_f == *m_score_t)
    {
        *m_score_f+=1;
    }
    percent_f = round(100* *m_score_f/(*m_score_f+*m_score_t));
    if(*m_score_j == *m_score_p)
    {
        *m_score_p+=1;
    }
    percent_p = round(100* *m_score_p/(*m_score_j+*m_score_p));

    percent_e = 100 - percent_i;
    percent_n = 100 - percent_s;
    percent_t = 100 - percent_f;
    percent_j = 100 - percent_p;

}
