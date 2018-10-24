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
 static void _difusfunc(ldifusfunc2_t, _NrnThread*);
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__KExtNodeBell
#define _nrn_initial _nrn_initial__KExtNodeBell
#define nrn_cur _nrn_cur__KExtNodeBell
#define _nrn_current _nrn_current__KExtNodeBell
#define nrn_jacob _nrn_jacob__KExtNodeBell
#define nrn_state _nrn_state__KExtNodeBell
#define _net_receive _net_receive__KExtNodeBell 
#define conc conc__KExtNodeBell 
 
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
#define Dk _p[0]
#define ik _p[1]
#define ko _p[2]
#define Dko _p[3]
#define v _p[4]
#define _g _p[5]
#define _ion_ik	*_ppvar[0]._pval
#define _ion_ko	*_ppvar[1]._pval
#define _style_k	*((int*)_ppvar[2]._pvoid)
#define _ion_dikdv	*_ppvar[3]._pval
 
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
 /* declaration of user functions */
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
 "setdata_KExtNodeBell", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
 static int _thread1data_inuse = 0;
static double _thread1data[4];
#define _gth 2
#define crossSectionalArea_KExtNodeBell _thread1data[0]
#define crossSectionalArea _thread[_gth]._pval[0]
#define extracellularVolumePerLength_KExtNodeBell _thread1data[1]
#define extracellularVolumePerLength _thread[_gth]._pval[1]
#define kbathVolumePerLength kbathVolumePerLength_KExtNodeBell
 double kbathVolumePerLength = 1e+015;
#define ko0 ko0_KExtNodeBell
 double ko0 = 4.30794;
#define kbath kbath_KExtNodeBell
 double kbath = 4.30794;
#define nodalGap nodalGap_KExtNodeBell
 double nodalGap = 1.9;
#define radialRateConstant_KExtNodeBell _thread1data[2]
#define radialRateConstant _thread[_gth]._pval[2]
#define radialCrosssectionalAreaPerLength_KExtNodeBell _thread1data[3]
#define radialCrosssectionalAreaPerLength _thread[_gth]._pval[3]
#define rn rn_KExtNodeBell
 double rn = 0.95;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "ko0_KExtNodeBell", "mM",
 "nodalGap_KExtNodeBell", "um",
 "rn_KExtNodeBell", "um",
 "extracellularVolumePerLength_KExtNodeBell", "um2",
 "crossSectionalArea_KExtNodeBell", "um2",
 "kbathVolumePerLength_KExtNodeBell", "um2",
 "radialCrosssectionalAreaPerLength_KExtNodeBell", "um",
 "radialRateConstant_KExtNodeBell", "um2/ms",
 "kbath_KExtNodeBell", "mM",
 "Dk_KExtNodeBell", "um2/ms",
 0,0
};
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "ko0_KExtNodeBell", &ko0_KExtNodeBell,
 "nodalGap_KExtNodeBell", &nodalGap_KExtNodeBell,
 "rn_KExtNodeBell", &rn_KExtNodeBell,
 "extracellularVolumePerLength_KExtNodeBell", &extracellularVolumePerLength_KExtNodeBell,
 "crossSectionalArea_KExtNodeBell", &crossSectionalArea_KExtNodeBell,
 "kbathVolumePerLength_KExtNodeBell", &kbathVolumePerLength_KExtNodeBell,
 "radialCrosssectionalAreaPerLength_KExtNodeBell", &radialCrosssectionalAreaPerLength_KExtNodeBell,
 "radialRateConstant_KExtNodeBell", &radialRateConstant_KExtNodeBell,
 "kbath_KExtNodeBell", &kbath_KExtNodeBell,
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
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"KExtNodeBell",
 "Dk_KExtNodeBell",
 0,
 0,
 0,
 0};
 static Symbol* _k_sym;
 static int _type_ik;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 6, _prop);
 	/*initialize range parameters*/
 	Dk = 1.85;
 	_prop->param = _p;
 	_prop->param_size = 6;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
  _type_ik = prop_ion->_type;
 nrn_check_conc_write(_prop, prop_ion, 0);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* ko */
 	_ppvar[2]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for k */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _KExtNodeBell_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 4);
  _extcall_thread = (Datum*)ecalloc(3, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
  _thread1data_inuse = 0;
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 6, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "#k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_ldifus1(_difusfunc);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 KExtNodeBell C:/Users/joeya/Desktop/NEURON_models/TestCNOW/KExtNodeBell.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96485.3;
 static double PI = 3.14159;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1]; static double *_temp1;
 static int conc();
 
static int conc (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<1;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( crossSectionalArea) ;
_MATELM1(0, 0) *= ( crossSectionalArea);  }
 /* COMPARTMENT crossSectionalArea {
     ko }
   */
 /* COMPARTMENT kbathVolumePerLength {
     }
   */
 /* LONGITUDINAL_DIFFUSION Dk * extracellularVolumePerLength {
     ko }
   */
 /* ~ ko < < ( ik / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 0) += (b_flux =   ( ik / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) ) );
 /*FLUX*/
  /* ~ ko <-> kbath ( radialRateConstant , radialRateConstant )*/
 f_flux =  radialRateConstant * ko ;
 b_flux =  radialRateConstant * kbath ;
 _RHS1( 0) -= (f_flux - b_flux);
 
 _term =  radialRateConstant ;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<1;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT crossSectionalArea {
   ko }
 */
 /* COMPARTMENT kbathVolumePerLength {
   }
 */
 /* LONGITUDINAL_DIFFUSION Dk * extracellularVolumePerLength {
   ko }
 */
 /* ~ ko < < ( ik / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) )*/
 f_flux = b_flux = 0.;
 Dko += (b_flux =   ( ik / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) ) );
 /*FLUX*/
  /* ~ ko <-> kbath ( radialRateConstant , radialRateConstant )*/
 f_flux =  radialRateConstant * ko ;
 b_flux =  radialRateConstant * kbath ;
 Dko -= (f_flux - b_flux);
 
 /*REACTION*/
  _p[_dlist1[0]] /= ( crossSectionalArea);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<1;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( crossSectionalArea) ;
_MATELM1(0, 0) *= ( crossSectionalArea);  }
 /* COMPARTMENT crossSectionalArea {
 ko }
 */
 /* COMPARTMENT kbathVolumePerLength {
 }
 */
 /* LONGITUDINAL_DIFFUSION Dk * extracellularVolumePerLength {
 ko }
 */
 /* ~ ko < < ( ik / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) )*/
 /*FLUX*/
  /* ~ ko <-> kbath ( radialRateConstant , radialRateConstant )*/
 _term =  radialRateConstant ;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
    } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 1;}
 
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
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 	_pv[0] = &(_ion_ko);
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 1, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
 
static void _thread_mem_init(Datum* _thread) {
  if (_thread1data_inuse) {_thread[_gth]._pval = (double*)ecalloc(4, sizeof(double));
 }else{
 _thread[_gth]._pval = _thread1data; _thread1data_inuse = 1;
 }
 }
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
  if (_thread[_gth]._pval == _thread1data) {
   _thread1data_inuse = 0;
  }else{
   free((void*)_thread[_gth]._pval);
  }
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_k_sym, _ppvar, 3, 4);
 }
 static void* _difspace1;
extern double nrn_nernst_coef();
static double _difcoef1(int _i, double* _p, Datum* _ppvar, double* _pdvol, double* _pdfcdc, Datum* _thread, _NrnThread* _nt) {
   *_pdvol =  crossSectionalArea ;
 if (_i == 0) {
  *_pdfcdc = nrn_nernst_coef(_type_ik)*( ( _ion_dikdv  / ( FARADAY ) * 2.0 * PI * rn * ( 1e4 ) ));
 }else{ *_pdfcdc=0.;}
   return Dk * extracellularVolumePerLength ;
}
 static void _difusfunc(ldifusfunc2_t _f, _NrnThread* _nt) {int _i;
  (*_f)(_mechtype, _difcoef1, &_difspace1, 0,  -2, 3 , _nt);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   ko = ko0 ;
   extracellularVolumePerLength = PI * ( pow( ( rn + nodalGap ) , 2.0 ) - pow( rn , 2.0 ) ) ;
   crossSectionalArea = extracellularVolumePerLength ;
   radialCrosssectionalAreaPerLength = 2.0 * PI * ( rn + nodalGap ) ;
   radialRateConstant = Dk * radialCrosssectionalAreaPerLength / nodalGap ;
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

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
 {  sparse_thread(&_thread[_spth1]._pvoid, 1, _slist1, _dlist1, _p, &t, dt, conc, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 1; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
  _ion_ko = ko;
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(ko) - _p;  _dlist1[0] = &(Dko) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
