#ifndef KROHR_IMPL_H
#define KROHR_IMPL_H
#include "krohr.h"
#include "trohr.h"

#include <qlineedit.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <klocale.h>
#include <qwhatsthis.h>


class KRohr_Impl : public KRohr
{ 
    Q_OBJECT

public:
    KRohr_Impl( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~KRohr_Impl();

  /** Konstruktor mit der Möglichkeit direkt auf eine Variable trohr zuzugreifen */
   KRohr_Impl(Trohr * r, QWidget * parent=0, const char * name=0, bool modal=0, WFlags fl=0);

  /** Setting the Trohr-object on which we are working with this class to version defined
outside of this class. */
  int attach_trohr(Trohr * r);

private:
		Trohr * rohr;
		bool delete_rohr;
		
		void set_values_from_trohr();
		
private slots:
		void calculate_results();
		void get_values();		

};

#endif // KROHR_IMPL_H
