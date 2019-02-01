#ifndef CALC_H
#define CALC_H

#include <QObject>

class QLineEdit;
class QString;

class Calc : public QObject {
    Q_OBJECT

public:
    explicit Calc(QObject *parent = nullptr);
    ~Calc();

    void setDispaly(QLineEdit*);

public slots:
    void calculate(void);
private:
    QLineEdit *m_display = nullptr;
    bool m_fl = 0;
    float m_num1 = 0;
    float m_num2 = 0;
    float m_res = 0;
    QString m_ops;
};

#endif // CALC_H
