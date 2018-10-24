#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _AXNODE_reg();
extern void _AXNODEKExt_reg();
extern void _AXNODEwKacc_reg();
extern void _Bi_train_reg();
extern void _CycleSineRamp_reg();
extern void _KExtNode_reg();
extern void _KExtNodeBell_reg();
extern void _KExtNodeNsh_reg();
extern void _KExtNodediff_reg();
extern void _KExtNodefh_reg();
extern void _KIntNode_reg();
extern void _KIntNodeND_reg();
extern void _MODSINCLAMP_reg();
extern void _NaExtNode_reg();
extern void _NaExtNodeND_reg();
extern void _NaIntNode_reg();
extern void _Nakpump_reg();
extern void _SINCLAMP_reg();
extern void _SineRamp_reg();
extern void _TRICLAMP_reg();
extern void _izap_reg();

modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," AXNODE.mod");
fprintf(stderr," AXNODEKExt.mod");
fprintf(stderr," AXNODEwKacc.mod");
fprintf(stderr," Bi_train.mod");
fprintf(stderr," CycleSineRamp.MOD");
fprintf(stderr," KExtNode.mod");
fprintf(stderr," KExtNodeBell.mod");
fprintf(stderr," KExtNodeNsh.mod");
fprintf(stderr," KExtNodediff.mod");
fprintf(stderr," KExtNodefh.mod");
fprintf(stderr," KIntNode.mod");
fprintf(stderr," KIntNodeND.mod");
fprintf(stderr," MODSINCLAMP.MOD");
fprintf(stderr," NaExtNode.mod");
fprintf(stderr," NaExtNodeND.mod");
fprintf(stderr," NaIntNode.mod");
fprintf(stderr," Nakpump.mod");
fprintf(stderr," SINCLAMP.MOD");
fprintf(stderr," SineRamp.MOD");
fprintf(stderr," TRICLAMP.MOD");
fprintf(stderr," izap.mod");
fprintf(stderr, "\n");
    }
_AXNODE_reg();
_AXNODEKExt_reg();
_AXNODEwKacc_reg();
_Bi_train_reg();
_CycleSineRamp_reg();
_KExtNode_reg();
_KExtNodeBell_reg();
_KExtNodeNsh_reg();
_KExtNodediff_reg();
_KExtNodefh_reg();
_KIntNode_reg();
_KIntNodeND_reg();
_MODSINCLAMP_reg();
_NaExtNode_reg();
_NaExtNodeND_reg();
_NaIntNode_reg();
_Nakpump_reg();
_SINCLAMP_reg();
_SineRamp_reg();
_TRICLAMP_reg();
_izap_reg();
}
