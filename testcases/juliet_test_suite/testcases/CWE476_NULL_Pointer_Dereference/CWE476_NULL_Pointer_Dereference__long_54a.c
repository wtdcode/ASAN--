/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_54a.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__long_54b_badSink(long * data);

void CWE476_NULL_Pointer_Dereference__long_54_bad()
{
    long * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    CWE476_NULL_Pointer_Dereference__long_54b_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__long_54b_goodG2BSink(long * data);

static void goodG2B()
{
    long * data;
    /* FIX: Initialize data */
    {
        long tmpData = 5L;
        data = &tmpData;
    }
    CWE476_NULL_Pointer_Dereference__long_54b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE476_NULL_Pointer_Dereference__long_54b_goodB2GSink(long * data);

static void goodB2G()
{
    long * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    CWE476_NULL_Pointer_Dereference__long_54b_goodB2GSink(data);
}

void CWE476_NULL_Pointer_Dereference__long_54_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE476_NULL_Pointer_Dereference__long_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__long_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
