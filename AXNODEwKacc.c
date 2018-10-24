/* Created by Language version: 7.5.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__axnodewkacc
#define _nrn_initial _nrn_initial__axnodewkacc
#define nrn_cur _nrn_cur__axnodewkacc
#define _nrn_current _nrn_current__axnodewkacc
#define nrn_jacob _nrn_jacob__axnodewkacc
#define nrn_state _nrn_state__axnodewkacc
#define _net_receive _net_receive__axnodewkacc 
#define evaluate_fct evaluate_fct__axnodewkacc 
#define states states__axnodewkacc 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gnapbar _p[0]
#define gnabar _p[1]
#define gkbar _p[2]
#define gl _p[3]
#define ena _p[4]
#define ek _p[5]
#define el _p[6]
#define fhspace _p[7]
#define txfer _p[8]
#define inap _p[9]
#define ina _p[10]
#define il _p[11]
#define mp_inf _p[12]
#define m_inf _p[13]
#define h_inf _p[14]
#define s_inf _p[15]
#define tau_mp _p[16]
#define tau_m _p[17]
#define tau_h _p[18]
#define tau_s _p[19]
#define mp _p[20]
#define m _p[21]
#define h _p[22]
#define s _p[23]
#define Dmp _p[24]
#define Dm _p[25]
#define Dh _p[26]
#define Ds _p[27]
#define ko _p[28]
#define Dko _p[29]
#define ik _p[30]
#define q10_1 _p[31]
#define q10_2 _p[32]
#define q10_3 _p[33]
#define v _p[34]
#define _g _p[35]
#define _ion_ik	*_ppvar[0]._pval
#define _ion_ko	*_ppvar[1]._pval
#define _style_k	*((int*)_ppvar[2]._pvoid)
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_Exp(void);
 static void _hoc_evaluate_fct(void);
 static void _hoc_vtrap(void);
 static void _hoc_vtrap8(void);
 static void _hoc_vtrap7(void);
 static void _hoc_vtrap6(void);
 static void _hoc_vtrap2(void);
 static void _hoc_vtrap1(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_axnodewkacc", _hoc_setdata,
 "Exp_axnodewkacc", _hoc_Exp,
 "evaluate_fct_axnodewkacc", _hoc_evaluate_fct,
 "vtrap_axnodewkacc", _hoc_vtrap,
 "vtrap8_axnodewkacc", _hoc_vtrap8,
 "vtrap7_axnodewkacc", _hoc_vtrap7,
 "vtrap6_axnodewkacc", _hoc_vtrap6,
 "vtrap2_axnodewkacc", _hoc_vtrap2,
 "vtrap1_axnodewkacc", _hoc_vtrap1,
 0, 0
};
#define Exp Exp_axnodewkacc
#define vtrap vtrap_axnodewkacc
#define vtrap8 vtrap8_axnodewkacc
#define vtrap7 vtrap7_axnodewkacc
#define vtrap6 vtrap6_axnodewkacc
#define vtrap2 vtrap2_axnodewkacc
#define vtrap1 vtrap1_axnodewkacc
 extern double Exp( _threadargsprotocomma_ double );
 extern double vtrap( _threadargsprotocomma_ double );
 extern double vtrap8( _threadargsprotocomma_ double );
 extern double vtrap7( _threadargsprotocomma_ double );
 extern double vtrap6( _threadargsprotocomma_ double );
 extern double vtrap2( _threadargsprotocomma_ double );
 extern double vtrap1( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define asC asC_axnodewkacc
 double asC = -5;
#define asB asB_axnodewkacc
 double asB = -27;
#define asA asA_axnodewkacc
 double asA = 0.3;
#define ahC ahC_axnodewkacc
 double ahC = 11;
#define ahB ahB_axnodewkacc
 double ahB = 114;
#define ahA ahA_axnodewkacc
 double ahA = 0.062;
#define amC amC_axnodewkacc
 double amC = 10.3;
#define amB amB_axnodewkacc
 double amB = 21.4;
#define amA amA_axnodewkacc
 double amA = 1.86;
#define ampC ampC_axnodewkacc
 double ampC = 10.2;
#define ampB ampB_axnodewkacc
 double ampB = 27;
#define ampA ampA_axnodewkacc
 double ampA = 0.01;
#define bsC bsC_axnodewkacc
 double bsC = -1;
#define bsB bsB_axnodewkacc
 double bsB = 10;
#define bsA bsA_axnodewkacc
 double bsA = 0.03;
#define bhC bhC_axnodewkacc
 double bhC = 13.4;
#define bhB bhB_axnodewkacc
 double bhB = 31.8;
#define bhA bhA_axnodewkacc
 double bhA = 2.3;
#define bmC bmC_axnodewkacc
 double bmC = 9.16;
#define bmB bmB_axnodewkacc
 double bmB = 25.7;
#define bmA bmA_axnodewkacc
 double bmA = 0.086;
#define bmpC bmpC_axnodewkacc
 double bmpC = 10;
#define bmpB bmpB_axnodewkacc
 double bmpB = 34;
#define bmpA bmpA_axnodewkacc
 double bmpA = 0.00025;
#define kbath kbath_axnodewkacc
 double kbath = 4.30794;
#define vtraub vtraub_axnodewkacc
 double vtraub = -80;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "kbath_axnodewkacc", "mM",
 "gnapbar_axnodewkacc", "mho/cm2",
 "gnabar_axnodewkacc", "mho/cm2",
 "gkbar_axnodewkacc", "mho/cm2",
 "gl_axnodewkacc", "mho/cm2",
 "ena_axnodewkacc", "mV",
 "ek_axnodewkacc", "mV",
 "el_axnodewkacc", "mV",
 "fhspace_axnodewkacc", "angstrom",
 "txfer_axnodewkacc", "ms",
 "inap_axnodewkacc", "mA/cm2",
 "ina_axnodewkacc", "mA/cm2",
 "il_axnodewkacc", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double ko0 = 0;
 static double m0 = 0;
 static double mp0 = 0;
 static double s0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vtraub_axnodewkacc", &vtraub_axnodewkacc,
 "ampA_axnodewkacc", &ampA_axnodewkacc,
 "ampB_axnodewkacc", &ampB_axnodewkacc,
 "ampC_axnodewkacc", &ampC_axnodewkacc,
 "bmpA_axnodewkacc", &bmpA_axnodewkacc,
 "bmpB_axnodewkacc", &bmpB_axnodewkacc,
 "bmpC_axnodewkacc", &bmpC_axnodewkacc,
 "amA_axnodewkacc", &amA_axnodewkacc,
 "amB_axnodewkacc", &amB_axnodewkacc,
 "amC_axnodewkacc", &amC_axnodewkacc,
 "bmA_axnodewkacc", &bmA_axnodewkacc,
 "bmB_axnodewkacc", &bmB_axnodewkacc,
 "bmC_axnodewkacc", &bmC_axnodewkacc,
 "ahA_axnodewkacc", &ahA_axnodewkacc,
 "ahB_axnodewkacc", &ahB_axnodewkacc,
 "ahC_axnodewkacc", &ahC_axnodewkacc,
 "bhA_axnodewkacc", &bhA_axnodewkacc,
 "bhB_axnodewkacc", &bhB_axnodewkacc,
 "bhC_axnodewkacc", &bhC_axnodewkacc,
 "asA_axnodewkacc", &asA_axnodewkacc,
 "asB_axnodewkacc", &asB_axnodewkacc,
 "asC_axnodewkacc", &asC_axnodewkacc,
 "bsA_axnodewkacc", &bsA_axnodewkacc,
 "bsB_axnodewkacc", &bsB_axnodewkacc,
 "bsC_axnodewkacc", &bsC_axnodewkacc,
 "kbath_axnodewkacc", &kbath_axnodewkacc,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"axnodewkacc",
 "gnapbar_axnodewkacc",
 "gnabar_axnodewkacc",
 "gkbar_axnodewkacc",
 "gl_axnodewkacc",
 "ena_axnodewkacc",
 "ek_axnodewkacc",
 "el_axnodewkacc",
 "fhspace_axnodewkacc",
 "txfer_axnodewkacc",
 0,
 "inap_axnodewkacc",
 "ina_axnodewkacc",
 "il_axnodewkacc",
 "mp_inf_axnodewkacc",
 "m_inf_axnodewkacc",
 "h_inf_axnodewkacc",
 "s_inf_axnodewkacc",
 "tau_mp_axnodewkacc",
 "tau_m_axnodewkacc",
 "tau_h_axnodewkacc",
 "tau_s_axnodewkacc",
 0,
 "mp_axnodewkacc",
 "m_axnodewkacc",
 "h_axnodewkacc",
 "s_axnodewkacc",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 36, _prop);
 	/*initialize range parameters*/
 	gnapbar = 0.01;
 	gnabar = 3;
 	gkbar = 0.08;
 	gl = 0.007;
 	ena = 50;
 	ek = -90;
 	el = -90;
 	fhspace = 30000;
 	txfer = 5;
 	_prop->param = _p;
 	_prop->param_size = 36;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_check_conc_write(_prop, prop_ion, 0);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* ko */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for k */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _AXNODEwKacc_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 36, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "#k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 axnodewkacc C:/Users/joeya/Desktop/NEURON_models/TestCNOW/AXNODEwKacc.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96485.3;
static int _reset;
static char *modelname = "Motor Axon Node channels";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[5], _dlist1[5];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   evaluate_fct ( _threadargscomma_ v ) ;
   Dmp = ( mp_inf - mp ) / tau_mp ;
   Dm = ( m_inf - m ) / tau_m ;
   Dh = ( h_inf - h ) / tau_h ;
   Ds = ( s_inf - s ) / tau_s ;
   Dko = ( 1e8 ) * ik / ( fhspace * FARADAY ) + ( kbath - ko ) / txfer ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 evaluate_fct ( _threadargscomma_ v ) ;
 Dmp = Dmp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_mp )) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_h )) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s )) ;
 Dko = Dko  / (1. - dt*( ( ( ( - 1.0 ) ) ) / txfer )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   evaluate_fct ( _threadargscomma_ v ) ;
    mp = mp + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_mp)))*(- ( ( ( mp_inf ) ) / tau_mp ) / ( ( ( ( - 1.0 ) ) ) / tau_mp ) - mp) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_m)))*(- ( ( ( m_inf ) ) / tau_m ) / ( ( ( ( - 1.0 ) ) ) / tau_m ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_h)))*(- ( ( ( h_inf ) ) / tau_h ) / ( ( ( ( - 1.0 ) ) ) / tau_h ) - h) ;
    s = s + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_s)))*(- ( ( ( s_inf ) ) / tau_s ) / ( ( ( ( - 1.0 ) ) ) / tau_s ) - s) ;
    ko = ko + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / txfer)))*(- ( ( ( ( 1e8 ) )*( ik ) ) / ( fhspace * FARADAY ) + ( ( kbath ) ) / txfer ) / ( ( ( ( - 1.0 ) ) ) / txfer ) - ko) ;
   }
  return 0;
}
 
static int  evaluate_fct ( _threadargsprotocomma_ double _lv ) {
   double _la , _lb , _lv2 ;
 _la = q10_1 * vtrap1 ( _threadargscomma_ _lv ) ;
   _lb = q10_1 * vtrap2 ( _threadargscomma_ _lv ) ;
   tau_mp = 1.0 / ( _la + _lb ) ;
   mp_inf = _la / ( _la + _lb ) ;
   _la = q10_1 * vtrap6 ( _threadargscomma_ _lv ) ;
   _lb = q10_1 * vtrap7 ( _threadargscomma_ _lv ) ;
   tau_m = 1.0 / ( _la + _lb ) ;
   m_inf = _la / ( _la + _lb ) ;
   _la = q10_2 * vtrap8 ( _threadargscomma_ _lv ) ;
   _lb = q10_2 * bhA / ( 1.0 + Exp ( _threadargscomma_ - ( _lv + bhB ) / bhC ) ) ;
   tau_h = 1.0 / ( _la + _lb ) ;
   h_inf = _la / ( _la + _lb ) ;
   _lv2 = _lv - vtraub ;
   _la = q10_3 * asA / ( Exp ( _threadargscomma_ ( _lv2 + asB ) / asC ) + 1.0 ) ;
   _lb = q10_3 * bsA / ( Exp ( _threadargscomma_ ( _lv2 + bsB ) / bsC ) + 1.0 ) ;
   tau_s = 1.0 / ( _la + _lb ) ;
   s_inf = _la / ( _la + _lb ) ;
    return 0; }
 
static void _hoc_evaluate_fct(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 evaluate_fct ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap;
 if ( _lx < - 50.0 ) {
     _lvtrap = 0.0 ;
     }
   else {
     _lvtrap = bsA / ( Exp ( _threadargscomma_ ( _lx + bsB ) / bsC ) + 1.0 ) ;
     }
   
return _lvtrap;
 }
 
static void _hoc_vtrap(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap1 ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap1;
 if ( fabs ( ( _lx + ampB ) / ampC ) < 1e-6 ) {
     _lvtrap1 = ampA * ampC ;
     }
   else {
     _lvtrap1 = ( ampA * ( _lx + ampB ) ) / ( 1.0 - Exp ( _threadargscomma_ - ( _lx + ampB ) / ampC ) ) ;
     }
   
return _lvtrap1;
 }
 
static void _hoc_vtrap1(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap1 ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap2 ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap2;
 if ( fabs ( ( _lx + bmpB ) / bmpC ) < 1e-6 ) {
     _lvtrap2 = - bmpA * bmpC ;
     }
   else {
     _lvtrap2 = ( bmpA * ( - ( _lx + bmpB ) ) ) / ( 1.0 - Exp ( _threadargscomma_ ( _lx + bmpB ) / bmpC ) ) ;
     }
   
return _lvtrap2;
 }
 
static void _hoc_vtrap2(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap2 ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap6 ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap6;
 if ( fabs ( ( _lx + amB ) / amC ) < 1e-6 ) {
     _lvtrap6 = amA * amC ;
     }
   else {
     _lvtrap6 = ( amA * ( _lx + amB ) ) / ( 1.0 - Exp ( _threadargscomma_ - ( _lx + amB ) / amC ) ) ;
     }
   
return _lvtrap6;
 }
 
static void _hoc_vtrap6(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap6 ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap7 ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap7;
 if ( fabs ( ( _lx + bmB ) / bmC ) < 1e-6 ) {
     _lvtrap7 = - bmA * bmC ;
     }
   else {
     _lvtrap7 = ( bmA * ( - ( _lx + bmB ) ) ) / ( 1.0 - Exp ( _threadargscomma_ ( _lx + bmB ) / bmC ) ) ;
     }
   
return _lvtrap7;
 }
 
static void _hoc_vtrap7(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap7 ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double vtrap8 ( _threadargsprotocomma_ double _lx ) {
   double _lvtrap8;
 if ( fabs ( ( _lx + ahB ) / ahC ) < 1e-6 ) {
     _lvtrap8 = - ahA * ahC ;
     }
   else {
     _lvtrap8 = ( ahA * ( - ( _lx + ahB ) ) ) / ( 1.0 - Exp ( _threadargscomma_ ( _lx + ahB ) / ahC ) ) ;
     }
   
return _lvtrap8;
 }
 
static void _hoc_vtrap8(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  vtrap8 ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double Exp ( _threadargsprotocomma_ double _lx ) {
   double _lExp;
 if ( _lx < - 100.0 ) {
     _lExp = 0.0 ;
     }
   else {
     _lExp = exp ( _lx ) ;
     }
   
return _lExp;
 }
 
static void _hoc_Exp(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  Exp ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 5;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ik = _ion_ik;
  ko = _ion_ko;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_ko = ko;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 5; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[4] = &(_ion_ko);
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ik = _ion_ik;
  ko = _ion_ko;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 2);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
  mp = mp0;
  s = s0;
 {
   q10_1 = pow( 2.2 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   q10_2 = pow( 2.9 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   q10_3 = pow( 3.0 , ( ( celsius - 36.0 ) / 10.0 ) ) ;
   evaluate_fct ( _threadargscomma_ v ) ;
   mp = mp_inf ;
   m = m_inf ;
   h = h_inf ;
   s = s_inf ;
   ko = 4.30794 ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ik = _ion_ik;
  ko = _ion_ko;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_ko = ko;
  nrn_wrote_conc(_k_sym, (&(_ion_ko)) - 2, _style_k);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   inap = gnapbar * mp * mp * mp * ( v - ena ) ;
   ina = gnabar * m * m * m * h * ( v - ena ) ;
   ik = gkbar * s * ( v - ek ) ;
   il = gl * ( v - el ) ;
   }
 _current += ina;
 _current += inap;
 _current += il;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ik = _ion_ik;
  ko = _ion_ko;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
  _ion_ko = ko;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ik = _ion_ik;
  ko = _ion_ko;
 {   states(_p, _ppvar, _thread, _nt);
  }  _ion_ko = ko;
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mp) - _p;  _dlist1[0] = &(Dmp) - _p;
 _slist1[1] = &(m) - _p;  _dlist1[1] = &(Dm) - _p;
 _slist1[2] = &(h) - _p;  _dlist1[2] = &(Dh) - _p;
 _slist1[3] = &(s) - _p;  _dlist1[3] = &(Ds) - _p;
 _slist1[4] = &(ko) - _p;  _dlist1[4] = &(Dko) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
