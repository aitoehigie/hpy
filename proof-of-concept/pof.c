#include "hpy.h"

static HPy do_nothing(HPyContext ctx, HPy self, HPy args)
{
    HPy_RETURN_NONE;
}
HPY_FUNCTION(do_nothing)


static HPyMethodDef PofMethods[] = {
    {"do_nothing", _do_nothing, METH_NOARGS, ""},
    {NULL, NULL, 0, NULL}
};

static HPyModuleDef moduledef = {
    HPyModuleDef_HEAD_INIT,
    "pof",                      /* m_name */
    "HPy Proof of Concept",     /* m_doc */
    -1,                         /* m_size */
    PofMethods                  /* m_methods */
};


HPY_MODINIT_FUNC(pof)(HPyContext ctx)
{
    HPy m;
    m = HPyModule_Create(ctx, &moduledef);
    if (m == NULL)
        return NULL;
    return m;
}