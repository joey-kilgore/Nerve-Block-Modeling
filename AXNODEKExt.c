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
 
#define nrn_init _nrn_init__AXNODEKExt
#define _nrn_initial _nrn_initial__AXNODEKExt
#define nrn_cur _nrn_cur__AXNODEKExt
#define _nrn_current _nrn_current__AXNODEKExt
#define nrn_jacob _nrn_jacob__AXNODEKExt
#define nrn_state _nrn_state__AXNODEKExt
#define _net_receive _net_receive__AXNODEKExt 
#define evaluate_fct evaluate_fct__AXNODEKExt 
#define states states__AXNODEKExt 
 
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
#define el _p[5]
#define inap _p[6]
#define ina _p[7]
#define il _p[8]
#define mp_inf _p[9]
#define m_inf _p[10]
#define h_inf _p[11]
#define s_inf _p[12]
#define tau_mp _p[13]
#define tau_m _p[14]
#define tau_h _p[15]
#define tau_s _p[16]
#define mp _p[17]
#define m _p[18]
#define h _p[19]
#define s _p[20]
#define Dmp _p[21]
#define Dm _p[22]
#define Dh _p[23]
#define Ds _p[24]
#define ek _p[25]
#define ik _p[26]
#define q10_1 _p[27]
#define q10_2 _p[28]
#define q10_3 _p[29]
#define v _p[30]
#define _g _p[31]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
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
 "setdata_AXNODEKExt", _hoc_setdata,
 "Exp_AXNODEKExt", _hoc_Exp,
 "evaluate_fct_AXNODEKExt", _hoc_evaluate_fct,
 "vtrap_AXNODEKExt", _hoc_vtrap,
 "vtrap8_AXNODEKExt", _hoc_vtrap8,
 "vtrap7_AXNODEKExt", _hoc_vtrap7,
 "vtrap6_AXNODEKExt", _hoc_vtrap6,
 "vtrap2_AXNODEKExt", _hoc_vtrap2,
 "vtrap1_AXNODEKExt", _hoc_vtrap1,
 0, 0
};
#define Exp Exp_AXNODEKExt
#define vtrap vtrap_AXNODEKExt
#define vtrap8 vtrap8_AXNODEKExt
#define vtrap7 vtrap7_AXNODEKExt
#define vtrap6 vtrap6_AXNODEKExt
#define vtrap2 vtrap2_AXNODEKExt
#define vtrap1 vtrap1_AXNODEKExt
 extern double Exp( _threadargsprotocomma_ double );
 extern double vtrap( _threadargsprotocomma_ double );
 extern double vtrap8( _threadargsprotocomma_ double );
 extern double vtrap7( _threadargsprotocomma_ double );
 extern double vtrap6( _threadargsprotocomma_ double );
 extern double vtrap2( _threadargsprotocomma_ double );
 extern double vtrap1( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define asC asC_AXNODEKExt
 double asC = -5;
#define asB asB_AXNODEKExt
 double asB = -27;
#define asA asA_AXNODEKExt
 double asA = 0.3;
#define ahC ahC_AXNODEKExt
 double ahC = 11;
#define ahB ahB_AXNODEKExt
 double ahB = 114;
#define ahA ahA_AXNODEKExt
 double ahA = 0.062;
#define amC amC_AXNODEKExt
 double amC = 10.3;
#define amB amB_AXNODEKExt
 double amB = 21.4;
#define amA amA_AXNODEKExt
 double amA = 1.86;
#define ampC ampC_AXNODEKExt
 double ampC = 10.2;
#define ampB ampB_AXNODEKExt
 double ampB = 27;
#define ampA ampA_AXNODEKExt
 double ampA = 0.01;
#define bsC bsC_AXNODEKExt
 double bsC = -1;
#define bsB bsB_AXNODEKExt
 double bsB = 10;
#define bsA bsA_AXNODEKExt
 double bsA = 0.03;
#define bhC bhC_AXNODEKExt
 double bhC = 13.4;
#define bhB bhB_AXNODEKExt
 double bhB = 31.8;
#define bhA bhA_AXNODEKExt
 double bhA = 2.3;
#define bmC bmC_AXNODEKExt
 double bmC = 9.16;
#define bmB bmB_AXNODEKExt
 double bmB = 25.7;
#define bmA bmA_AXNODEKExt
 double bmA = 0.086;
#define bmpC bmpC_AXNODEKExt
 double bmpC = 10;
#define bmpB bmpB_AXNODEKExt
 double bmpB = 34;
#define bmpA bmpA_AXNODEKExt
 double bmpA = 0.00025;
#define vtraub vtraub_AXNODEKExt
 double vtraub = -80;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gnapbar_AXNODEKExt", "mho/cm2",
 "gnabar_AXNODEKExt", "mho/cm2",
 "gkbar_AXNODEKExt", "mho/cm2",
 "gl_AXNODEKExt", "mho/cm2",
 "ena_AXNODEKExt", "mV",
 "el_AXNODEKExt", "mV",
 "inap_AXNODEKExt", "mA/cm2",
 "ina_AXNODEKExt", "mA/cm2",
 "il_AXNODEKExt", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 static double mp0 = 0;
 static double s0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vtraub_AXNODEKExt", &vtraub_AXNODEKExt,
 "ampA_AXNODEKExt", &ampA_AXNODEKExt,
 "ampB_AXNODEKExt", &ampB_AXNODEKExt,
 "ampC_AXNODEKExt", &ampC_AXNODEKExt,
 "bmpA_AXNODEKExt", &bmpA_AXNODEKExt,
 "bmpB_AXNODEKExt", &bmpB_AXNODEKExt,
 "bmpC_AXNODEKExt", &bmpC_AXNODEKExt,
 "amA_AXNODEKExt", &amA_AXNODEKExt,
 "amB_AXNODEKExt", &amB_AXNODEKExt,
 "amC_AXNODEKExt", &amC_AXNODEKExt,
 "bmA_AXNODEKExt", &bmA_AXNODEKExt,
 "bmB_AXNODEKExt", &bmB_AXNODEKExt,
 "bmC_AXNODEKExt", &bmC_AXNODEKExt,
 "ahA_AXNODEKExt", &ahA_AXNODEKExt,
 "ahB_AXNODEKExt", &ahB_AXNODEKExt,
 "ahC_AXNODEKExt", &ahC_AXNODEKExt,
 "bhA_AXNODEKExt", &bhA_AXNODEKExt,
 "bhB_AXNODEKExt", &bhB_AXNODEKExt,
 "bhC_AXNODEKExt", &bhC_AXNODEKExt,
 "asA_AXNODEKExt", &asA_AXNODEKExt,
 "asB_AXNODEKExt", &asB_AXNODEKExt,
 "asC_AXNODEKExt", &asC_AXNODEKExt,
 "bsA_AXNODEKExt", &bsA_AXNODEKExt,
 "bsB_AXNODEKExt", &bsB_AXNODEKExt,
 "bsC_AXNODEKExt", &bsC_AXNODEKExt,
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
"AXNODEKExt",
 "gnapbar_AXNODEKExt",
 "gnabar_AXNODEKExt",
 "gkbar_AXNODEKExt",
 "gl_AXNODEKExt",
 "ena_AXNODEKExt",
 "el_AXNODEKExt",
 0,
 "inap_AXNODEKExt",
 "ina_AXNODEKExt",
 "il_AXNODEKExt",
 "mp_inf_AXNODEKExt",
 "m_inf_AXNODEKExt",
 "h_inf_AXNODEKExt",
 "s_inf_AXNODEKExt",
 "tau_mp_AXNODEKExt",
 "tau_m_AXNODEKExt",
 "tau_h_AXNODEKExt",
 "tau_s_AXNODEKExt",
 0,
 "mp_AXNODEKExt",
 "m_AXNODEKExt",
 "h_AXNODEKExt",
 "s_AXNODEKExt",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 32, _prop);
 	/*initialize range parameters*/
 	gnapbar = 0.01;
 	gnabar = 3;
 	gkbar = 0.08;
 	gl = 0.007;
 	ena = 50;
 	el = -90;
 	_prop->param = _p;
 	_prop->param_size = 32;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _AXNODEKExt_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 32, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 AXNODEKExt C:/Users/joeya/Desktop/NEURON_models/TestCNOW/AXNODEKExt.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Motor Axon Node channels";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int evaluate_fct(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   evaluate_fct ( _threadargscomma_ v ) ;
   Dmp = ( mp_inf - mp ) / tau_mp ;
   Dm = ( m_inf - m ) / tau_m ;
   Dh = ( h_inf - h ) / tau_h ;
   Ds = ( s_inf - s ) / tau_s ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 evaluate_fct ( _threadargscomma_ v ) ;
 Dmp = Dmp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_mp )) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_m )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_h )) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_s )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   evaluate_fct ( _threadargscomma_ v ) ;
    mp = mp + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_mp)))*(- ( ( ( mp_inf ) ) / tau_mp ) / ( ( ( ( - 1.0 ) ) ) / tau_mp ) - mp) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_m)))*(- ( ( ( m_inf ) ) / tau_m ) / ( ( ( ( - 1.0 ) ) ) / tau_m ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_h)))*(- ( ( ( h_inf ) ) / tau_h ) / ( ( ( ( - 1.0 ) ) ) / tau_h ) - h) ;
    s = s + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau_s)))*(- ( ( ( s_inf ) ) / tau_s ) / ( ( ( ( - 1.0 ) ) ) / tau_s ) - s) ;
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
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
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
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
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
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
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
 _current += ik;
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
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
  ek = _ion_ek;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

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
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
