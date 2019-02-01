#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QDebug>

#include "Calc.h"

Calc::Calc(QObject *parent) : QObject(parent) {

}

void Calc::setDispaly(QLineEdit *display) {
    m_display = display;
}

void Calc::calculate(void) {
    QPushButton *button;
    QString newVal, buttonVal, screenVal;

    /* Возвращает указатель на нажатую кнопку */
    button = qobject_cast<QPushButton*>(sender());

    if (button) {
        buttonVal = button->text();
        screenVal = m_display->text(); //screenval = 0 по дефолту

        if (buttonVal == "C") {
            m_fl = 0;
            newVal = "0";
            m_num1 = 0;
            m_num2 = 0;
        } else if (buttonVal == "+" ||
                   buttonVal == "-" ||
                   buttonVal == "*" ||
                   buttonVal == "/") {
            m_ops = buttonVal;
            newVal = buttonVal;
            m_fl = 1;
        } else if (buttonVal == "=") {
            if (m_ops == "+") {
                m_res = m_num1 + m_num2;
            }

            if (m_ops == "-") {
                m_res = m_num1 - m_num2;
            }

            if (m_ops == "*") {
                m_res = m_num1 * m_num2;
            }

            if (m_ops == "/") {
                m_res = m_num1 / m_num2;
            }

            newVal = QString::number(m_res);
            m_fl = 1;
            m_num1 = newVal.toFloat();
        } else {
            if(m_fl == 0) {
                if (screenVal == "0") {
                    m_num1 = buttonVal.toFloat();
                    newVal = buttonVal;
                } else {
                    m_num1 = (screenVal + buttonVal).toFloat();
                    newVal = screenVal + buttonVal;
                }
            } else if (m_fl == 1) {
                if (screenVal == "0" ||
                    screenVal == "+" ||
                    screenVal == "-" ||
                    screenVal == "*" ||
                    screenVal == "/"){
                    m_num2 = buttonVal.toFloat();
                    newVal = buttonVal;
                } else {
                    m_num2 = (screenVal + buttonVal).toFloat();
                    newVal = screenVal + buttonVal;
                }
            }
        }

        m_display->setText(newVal);
    } else {
        m_display->setText("Err");
    }
}

Calc::~Calc() {

}
