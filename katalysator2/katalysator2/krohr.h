/****************************************************************************
** Form interface generated from reading ui file './krohr.ui'
**
** Created: Fri Jul 20 23:54:57 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef KROHR_H
#define KROHR_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QFrame;
class QLCDNumber;
class QLabel;
class QLineEdit;
class QPushButton;
class QTabWidget;
class QWidget;

class KRohr : public QDialog
{ 
    Q_OBJECT

public:
    KRohr( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~KRohr();

    QTabWidget* tabWidget;
    QWidget* Widget4;
    QLabel* TextLabel2;
    QLabel* TextLabel1;
    QLabel* TextLabel3;
    QLineEdit* lenght_mm;
    QLineEdit* diameter_mm;
    QLineEdit* thickness_mm;
    QLabel* TextLabel1_3;
    QLineEdit* rohr_name;
    QFrame* Line1;
    QWidget* Widget5;
    QLabel* TextLabel5;
    QLabel* TextLabel6;
    QLabel* TextLabel7;
    QLabel* TextLabel4;
    QLineEdit* cp;
    QLineEdit* rho;
    QLineEdit* price_per_mass;
    QLineEdit* lambda;
    QWidget* tab;
    QLabel* TextLabel2_2;
    QLabel* TextLabel3_2;
    QLabel* TextLabel1_2;
    QLCDNumber* mass_kg;
    QLCDNumber* price;
    QLCDNumber* heat_capacity_kJK;
    QPushButton* buttonHelp;
    QPushButton* buttonApply;
    QPushButton* buttonOk;
    QPushButton* buttonCancel;

protected:
    QVBoxLayout* KRohrLayout;
    QGridLayout* Widget4Layout;
    QGridLayout* Widget5Layout;
    QGridLayout* tabLayout;
    QHBoxLayout* Layout1;
    bool event( QEvent* );
};

#endif // KROHR_H
