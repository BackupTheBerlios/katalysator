#include <klocale.h>
/****************************************************************************
** Form implementation generated from reading ui file './krohr.ui'
**
** Created: Sat Jul 28 13:18:15 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "krohr.h"

#include <qframe.h>
#include <qlabel.h>
#include <qlcdnumber.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a KRohr which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
KRohr::KRohr( QWidget* parent,  const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "KRohr" );
    resize( 500, 372 ); 
    setCaption( i18n( "MyDialog1" ) );
    setIconText( QString::null );
    setSizeGripEnabled( TRUE );
    KRohrLayout = new QVBoxLayout( this ); 
    KRohrLayout->setSpacing( 6 );
    KRohrLayout->setMargin( 11 );

    tabWidget = new QTabWidget( this, "tabWidget" );
    tabWidget->setCursor( QCursor( 0 ) );
    tabWidget->setTabShape( QTabWidget::Rounded );
    QToolTip::add(  tabWidget, QString::null );

    Widget4 = new QWidget( tabWidget, "Widget4" );
    Widget4Layout = new QGridLayout( Widget4 ); 
    Widget4Layout->setSpacing( 6 );
    Widget4Layout->setMargin( 11 );

    TextLabel2 = new QLabel( Widget4, "TextLabel2" );
    TextLabel2->setText( i18n( "diameter [mm]" ) );

    Widget4Layout->addWidget( TextLabel2, 3, 0 );

    TextLabel1 = new QLabel( Widget4, "TextLabel1" );
    TextLabel1->setText( i18n( "lenght [mm]" ) );

    Widget4Layout->addWidget( TextLabel1, 2, 0 );

    TextLabel3 = new QLabel( Widget4, "TextLabel3" );
    TextLabel3->setText( i18n( "wall thickness [mm]" ) );

    Widget4Layout->addWidget( TextLabel3, 4, 0 );

    lenght_mm = new QLineEdit( Widget4, "lenght_mm" );

    Widget4Layout->addWidget( lenght_mm, 2, 1 );

    diameter_mm = new QLineEdit( Widget4, "diameter_mm" );

    Widget4Layout->addWidget( diameter_mm, 3, 1 );

    thickness_mm = new QLineEdit( Widget4, "thickness_mm" );

    Widget4Layout->addWidget( thickness_mm, 4, 1 );

    TextLabel1_3 = new QLabel( Widget4, "TextLabel1_3" );
    TextLabel1_3->setText( i18n( "name" ) );

    Widget4Layout->addWidget( TextLabel1_3, 0, 0 );

    rohr_name = new QLineEdit( Widget4, "rohr_name" );

    Widget4Layout->addWidget( rohr_name, 0, 1 );

    Line1 = new QFrame( Widget4, "Line1" );
    Line1->setFrameStyle( QFrame::HLine | QFrame::Sunken );

    Widget4Layout->addMultiCellWidget( Line1, 1, 1, 0, 1 );
    tabWidget->insertTab( Widget4, i18n( "geometry" ) );

    Widget5 = new QWidget( tabWidget, "Widget5" );
    Widget5Layout = new QGridLayout( Widget5 ); 
    Widget5Layout->setSpacing( 6 );
    Widget5Layout->setMargin( 11 );

    TextLabel5 = new QLabel( Widget5, "TextLabel5" );
    TextLabel5->setText( i18n( "heat conductivity [kJ/(mK)]" ) );

    Widget5Layout->addWidget( TextLabel5, 1, 0 );

    TextLabel6 = new QLabel( Widget5, "TextLabel6" );
    TextLabel6->setText( i18n( QString::fromUtf8( "density [kg/m³]" ) ) );

    Widget5Layout->addWidget( TextLabel6, 2, 0 );

    TextLabel7 = new QLabel( Widget5, "TextLabel7" );
    TextLabel7->setText( i18n( "price per mass [EURO/kg]" ) );

    Widget5Layout->addWidget( TextLabel7, 3, 0 );

    TextLabel4 = new QLabel( Widget5, "TextLabel4" );
    TextLabel4->setText( i18n( "heat capacity [kJ/kgK]" ) );

    Widget5Layout->addWidget( TextLabel4, 0, 0 );

    cp = new QLineEdit( Widget5, "cp" );

    Widget5Layout->addWidget( cp, 0, 1 );

    rho = new QLineEdit( Widget5, "rho" );

    Widget5Layout->addWidget( rho, 2, 1 );

    price_per_mass = new QLineEdit( Widget5, "price_per_mass" );

    Widget5Layout->addWidget( price_per_mass, 3, 1 );

    lambda = new QLineEdit( Widget5, "lambda" );

    Widget5Layout->addWidget( lambda, 1, 1 );
    tabWidget->insertTab( Widget5, i18n( "physical data" ) );

    tab = new QWidget( tabWidget, "tab" );
    tabLayout = new QGridLayout( tab ); 
    tabLayout->setSpacing( 6 );
    tabLayout->setMargin( 11 );

    TextLabel2_2 = new QLabel( tab, "TextLabel2_2" );
    TextLabel2_2->setText( i18n( "heat capacity [kJ/K]" ) );

    tabLayout->addWidget( TextLabel2_2, 1, 0 );

    TextLabel3_2 = new QLabel( tab, "TextLabel3_2" );
    TextLabel3_2->setText( i18n( "Price [EURO]" ) );

    tabLayout->addWidget( TextLabel3_2, 2, 0 );

    TextLabel1_2 = new QLabel( tab, "TextLabel1_2" );
    TextLabel1_2->setText( i18n( "mass [kg]" ) );

    tabLayout->addWidget( TextLabel1_2, 0, 0 );

    mass_kg = new QLCDNumber( tab, "mass_kg" );
    QFont mass_kg_font(  mass_kg->font() );
    mass_kg_font.setBold( TRUE );
    mass_kg->setFont( mass_kg_font ); 
    mass_kg->setBackgroundOrigin( QLCDNumber::WidgetOrigin );
    mass_kg->setFrameShadow( QLCDNumber::Plain );
    mass_kg->setLineWidth( 1 );
    mass_kg->setMargin( 0 );
    mass_kg->setSegmentStyle( QLCDNumber::Filled );

    tabLayout->addWidget( mass_kg, 0, 1 );

    price = new QLCDNumber( tab, "price" );
    price->setMargin( 0 );
    price->setMode( QLCDNumber::DEC );
    price->setSegmentStyle( QLCDNumber::Filled );

    tabLayout->addWidget( price, 2, 1 );

    heat_capacity_kJK = new QLCDNumber( tab, "heat_capacity_kJK" );
    heat_capacity_kJK->setSegmentStyle( QLCDNumber::Filled );

    tabLayout->addWidget( heat_capacity_kJK, 1, 1 );
    tabWidget->insertTab( tab, i18n( "results" ) );
    KRohrLayout->addWidget( tabWidget );

    Layout1 = new QHBoxLayout; 
    Layout1->setSpacing( 6 );
    Layout1->setMargin( 0 );

    buttonHelp = new QPushButton( this, "buttonHelp" );
    buttonHelp->setText( i18n( "&Help" ) );
    buttonHelp->setAutoDefault( TRUE );
    Layout1->addWidget( buttonHelp );
    QSpacerItem* spacer = new QSpacerItem( 20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    Layout1->addItem( spacer );

    buttonApply = new QPushButton( this, "buttonApply" );
    buttonApply->setText( i18n( "&Apply" ) );
    buttonApply->setAutoDefault( TRUE );
    Layout1->addWidget( buttonApply );

    buttonOk = new QPushButton( this, "buttonOk" );
    buttonOk->setText( i18n( "&OK" ) );
    buttonOk->setAutoDefault( TRUE );
    buttonOk->setDefault( TRUE );
    Layout1->addWidget( buttonOk );

    buttonCancel = new QPushButton( this, "buttonCancel" );
    buttonCancel->setText( i18n( "&Cancel" ) );
    buttonCancel->setAutoDefault( TRUE );
    Layout1->addWidget( buttonCancel );
    KRohrLayout->addLayout( Layout1 );

    // signals and slots connections
    connect( buttonOk, SIGNAL( clicked() ), this, SLOT( accept() ) );
    connect( buttonCancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
KRohr::~KRohr()
{
    // no need to delete child widgets, Qt does it all for us
}

/*  
 *  Main event handler. Reimplemented to handle application
 *  font changes
 */
bool KRohr::event( QEvent* ev )
{
    bool ret = QDialog::event( ev ); 
    if ( ev->type() == QEvent::ApplicationFontChange ) {
	QFont mass_kg_font(  mass_kg->font() );
	mass_kg_font.setBold( TRUE );
	mass_kg->setFont( mass_kg_font ); 
    }
    return ret;
}

#include "krohr.moc"
