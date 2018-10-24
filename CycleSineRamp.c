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
 
#define nrn_init _nrn_init__CycleSineRamp
#define _nrn_initial _nrn_initial__CycleSineRamp
#define nrn_cur _nrn_cur__CycleSineRamp
#define _nrn_current _nrn_current__CycleSineRamp
#define nrn_jacob _nrn_jacob__CycleSineRamp
#define nrn_state _nrn_state__CycleSineRamp
#define _net_receive _net_receive__CycleSineRamp 
 
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
#define f _p[0]
#define i _p[1]
#define TimeStart _p[2]
#define DCAmp _p[3]
#define HFACAmp _p[4]
#define freq _p[5]
#define dDC _p[6]
#define dHFAC _p[7]
#define dfreq _p[8]
#define virtualt _p[9]
#define oldt _p[10]
#define oldfreq _p[11]
#define DCAmp_vec (_p + 12)
#define HFAC_vec (_p + 18)
#define freq_vec (_p + 24)
#define Ramptime_vec (_p + 30)
#define segment _p[36]
#define num_of_pts _p[37]
#define TimeStop _p[38]
#define cycletime _p[39]
#define freqsample _p[40]
#define newendtime _p[41]
#define v _p[42]
#define _g _p[43]
#define _nd_area  *_ppvar[0]._pval
 
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
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "f", "Hz",
 "i", "nA",
 "TimeStart", "ms",
 "DCAmp", "nA",
 "HFACAmp", "nA",
 "freq", "Hz",
 "dDC", "nA",
 "dHFAC", "nA",
 "dfreq", "Hz",
 "virtualt", "sec",
 "oldt", "ms",
 "oldfreq", "Hz",
 "DCAmp_vec", "nA",
 "HFAC_vec", "nA",
 "freq_vec", "nA",
 "Ramptime_vec", "ms",
 "TimeStop", "ms",
 "cycletime", "ms",
 "freqsample", "Hz",
 0,0
};
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"CycleSineRamp",
 "f",
 0,
 "i",
 "TimeStart",
 "DCAmp",
 "HFACAmp",
 "freq",
 "dDC",
 "dHFAC",
 "dfreq",
 "virtualt",
 "oldt",
 "oldfreq",
 "DCAmp_vec[6]",
 "HFAC_vec[6]",
 "freq_vec[6]",
 "Ramptime_vec[6]",
 "segment",
 "num_of_pts",
 "TimeStop",
 "cycletime",
 "freqsample",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 44, _prop);
 	/*initialize range parameters*/
 	f = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 44;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _CycleSineRamp_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_prop_size(_mechtype, 44, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 CycleSineRamp C:/Users/joeya/Desktop/NEURON_models/TestCNOW/CycleSineRamp.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double PI = 3.14159;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
 {
   i = 0.0 ;
   TimeStart = 0.0 ;
   oldt = 0.0 ;
   oldfreq = 500.0 ;
   DCAmp_vec [ 0 ] = 0.0 ;
   HFAC_vec [ 0 ] = 0.0 ;
   freq_vec [ 0 ] = 0.0 ;
   segment = 0.0 ;
   TimeStop = Ramptime_vec [ 1 ] ;
   if ( TimeStop > 0.0 ) {
     DCAmp = 0.0 ;
     HFACAmp = 0.0 ;
     freq = 0.0 ;
     }
   else {
     DCAmp = DCAmp_vec [ 1 ] ;
     HFACAmp = HFAC_vec [ 1 ] ;
     freq = freq_vec [ 1 ] ;
     }
   dDC = 0.0 ;
   dHFAC = 0.0 ;
   dfreq = 0.0 ;
   virtualt = 0.0 ;
   cycletime = 0.0 ;
   freqsample = 0.0 ;
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
#if EXTRACELLULAR
 _nd = _ml->_nodelist[_iml];
 if (_nd->_extnode) {
    _v = NODEV(_nd) +_nd->_extnode->_v[0];
 }else
#endif
 {
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
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   if ( t < TimeStop ) {
     i = ( HFACAmp * sin ( 2.0 * PI * freq_vec [ ((int) segment ) + 1 ] * ( virtualt ) / 1000.0 ) ) + DCAmp ;
     oldfreq = freq ;
     dDC = ( DCAmp_vec [ ((int) segment ) + 1 ] - DCAmp_vec [ ((int) segment ) ] ) / Ramptime_vec [ ((int) segment ) + 1 ] * ( dt / 2.0 ) ;
     dHFAC = ( HFAC_vec [ ((int) segment ) + 1 ] - HFAC_vec [ ((int) segment ) ] ) / Ramptime_vec [ ((int) segment ) + 1 ] * ( dt / 2.0 ) ;
     dfreq = ( freq_vec [ ((int) segment ) + 1 ] - freq_vec [ ((int) segment ) ] ) / ( Ramptime_vec [ ((int) segment ) + 1 ] ) * ( dt / 2.0 ) ;
     DCAmp = dDC + DCAmp ;
     HFACAmp = dHFAC + HFACAmp ;
     freq = dfreq + freq ;
     if ( freq  != 0.0 ) {
       if ( cycletime  == 0.0 ) {
         freqsample = freq ;
         }
       if ( cycletime < 2.0 * ( 1000.0 / freq_vec [ ((int) segment ) + 1 ] ) ) {
         virtualt = virtualt + dt / 2.0 ;
         }
       else {
         virtualt = 0.0 ;
         freqsample = freq ;
         }
       if ( cycletime > ( 1000.0 / freqsample ) ) {
         cycletime = 0.0 ;
         }
       else {
         cycletime = cycletime + dt ;
         }
       }
     }
   else if ( segment < num_of_pts ) {
     segment = segment + 1.0 ;
     TimeStop = TimeStop + Ramptime_vec [ ((int) segment ) + 1 ] ;
     }
   else {
     i = ( HFACAmp * sin ( 2.0 * PI * freq * ( virtualt ) / 1000.0 ) ) + DCAmp ;
     virtualt = virtualt + dt / 2.0 ;
     }
   }
 _current += i;

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
#if EXTRACELLULAR
 _nd = _ml->_nodelist[_iml];
 if (_nd->_extnode) {
    _v = NODEV(_nd) +_nd->_extnode->_v[0];
 }else
#endif
 {
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
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) += _rhs;
  }else
#endif
  {
	NODERHS(_nd) += _rhs;
  }
  if (_nt->_nrn_fast_imem) { _nt->_nrn_fast_imem->_nrn_sav_rhs[_ni[_iml]] += _rhs; }
#if EXTRACELLULAR
 if (_nd->_extnode) {
   *_nd->_extnode->_rhs[0] += _rhs;
 }
#endif
 
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
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) -= _g;
  }else
#endif
  {
	NODED(_nd) -= _g;
  }
  if (_nt->_nrn_fast_imem) { _nt->_nrn_fast_imem->_nrn_sav_d[_ni[_iml]] -= _g; }
#if EXTRACELLULAR
 if (_nd->_extnode) {
   *_nd->_extnode->_d[0] += _g;
 }
#endif
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
