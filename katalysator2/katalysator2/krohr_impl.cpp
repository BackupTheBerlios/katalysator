#include "krohr_impl.h"

/* 
 *  Constructs a KRohr_Impl which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
KRohr_Impl::KRohr_Impl( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : KRohr( parent, name, modal, fl )
{
	connect(buttonApply, SIGNAL(clicked()), SLOT(get_values()));
	connect(buttonApply, SIGNAL(clicked()), SLOT(calculate_results()));

	connect(buttonOk, SIGNAL(clicked()), SLOT(get_values()));
	connect(buttonOk, SIGNAL(clicked()), SLOT(calculate_results()));

	rohr=new Trohr;
	delete_rohr=true;
	set_values_from_trohr();
//	setCaption( rohr->getname() );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
KRohr_Impl::~KRohr_Impl()
{
    // no need to delete child widgets, Qt does it all for us
    if(delete_rohr) delete rohr;
}

void KRohr_Impl::calculate_results()
{
	mass_kg->display(rohr->masse());
	heat_capacity_kJK->display(rohr->WKap());
  price->display(rohr->preis());
}

void KRohr_Impl::get_values()
{
	rohr->setdurchmesser(diameter_mm->text().toFloat()*1E-3);
	rohr->setlaenge(lenght_mm->text().toFloat()*1E-3);
	rohr->setwandstaerke(thickness_mm->text().toFloat()*1E-3);
	
	rohr->setlambda(lambda->text().toFloat());
	rohr->setrho(rho->text().toFloat());
	rohr->setcp(cp->text().toFloat());
	rohr->setpreis(price_per_mass->text().toFloat());
	QString temp=rohr_name->text();
	rohr->setname(temp);
//	rohr->set
}

void KRohr_Impl::set_values_from_trohr()
{
	QString wert;
	
	wert.setNum(rohr->getdurchmesser());
	diameter_mm->setText(wert);

	wert.setNum(rohr->getlaenge());
	lenght_mm->setText(wert);
	
	wert.setNum(rohr->getwandstaerke());
	thickness_mm->setText(wert);
	
	wert.setNum(rohr->getlambda());
	lambda->setText(wert);
	
	wert.setNum(rohr->getrho());
	rho->setText(wert);
	
	wert.setNum(rohr->getcp());
	cp->setText(wert);

	wert.setNum(rohr->getpreis());
	price_per_mass->setText(wert);
	
	rohr_name->setText(rohr->getname());
} // KRohr_Impl::set_values_from_trohr

/** Konstruktor mit der Möglichkeit direkt auf eine Variable trohr zuzugreifen */
 KRohr_Impl::KRohr_Impl(Trohr * r, QWidget * parent, const char * name, bool modal, WFlags fl)
    : KRohr( parent, name, modal, fl )

 {
	connect(buttonApply, SIGNAL(clicked()), SLOT(get_values()));
	connect(buttonApply, SIGNAL(clicked()), SLOT(calculate_results()));

	connect(buttonOk, SIGNAL(clicked()), SLOT(get_values()));
	connect(buttonOk, SIGNAL(clicked()), SLOT(calculate_results()));

	rohr=r;
	delete_rohr=false;
	set_values_from_trohr();

}
/** Setting the Trohr-object on which we are working with this class to version defined
outside of this class. */
int KRohr_Impl::attach_trohr(Trohr * r){
	if (r==0) return 1;
	if (delete_rohr) delete rohr;
	rohr=r;
	set_values_from_trohr();
	return 0;
}
