#include <QApplication>
#include <QWidget>
#include <QRadioButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWizard>

#ifndef PAGES_H
#define PAGES_H


class Pages : public QWizardPage
{
    public:
    Pages();
    Pages(QString introduction,int a);
    Pages(QString question, QString rep1, QString rep2, int a, char typeq, unsigned int score_type, unsigned int score_type_inv);
    //~Pages();

    void setQuestion(QString question);
    void setReponses(QString rep1, QString rep2);
    bool button1Checked() const;
    bool isComplete() const;
    char get_type() const;
    int get_score_input() const;

    private:
    QLabel *m_question;
    QRadioButton *m_rep1;
    QRadioButton *m_rep2;
    QVBoxLayout *m_layout;
    char *m_typeq;
    unsigned int *m_score_r1;
    unsigned int *m_score_r2;
};

#endif // PAGES_H
