#include <iostream>
#include <tcl.h>
#include <string>
using namespace std;

int main()
{
    cout<<"[In CPP] : Try to use \"Tcl_*\" related command to invoke proc1 procedure in test.tcl"<<endl;
    char command[100];
    sprintf(command, "proc1");
    Tcl_Interp *interp = Tcl_CreateInterp();
    if (Tcl_EvalFile(interp, "test.tcl") == TCL_OK) {
        if (Tcl_Eval(interp, command) == TCL_OK) {
            const char * result;
            result = Tcl_GetString(Tcl_GetObjResult(interp));
            cout<<"[In CPP] : result = "<<result<<endl;
        }
    }
    return 0;
}
