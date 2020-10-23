#include<Python.h>
#include<structmember.h>
#include<sstream>
#include<iostream>
using namespace std;


typedef struct FirstClass{

	PyObject_HEAD
	char* m_PlayerName;
	unsigned int m_PlayerID;
}FirstClass;

static void FirstClass_init(FirstClass* self, PyObject* pArgs){
	const char *Name = NULL;
	if ( !PyArg_ParseTuple(  pArgs, "sl",&Name,self->m_PlayerID ) ){
		std::cout << "init arg error" << endl;
		return;
	}
	self->m_PlayerName = new char[strlen(Name) + 1];
	strcpy(self->m_PlayerName,Name);
	
}

static void FirstClass_Destruct(FirstClass* self){
	if(self->m_PlayerName)
		delete[] self->m_PlayerName;
	Py_TYPE(self)->tp_free( (PyObject*) self);
	
}

static PyObject* FirstClass_Str(FirstClass* self){
	ostringstream o;
	o << "Name: " << self->m_PlayerName << "ID: " << self->m_PlayerID;
	string s = o.str();
	return Py_BuildValue("s",s.c_str());
}


static PyObject* FirstClass_Repr(FirstClass* self){

	return FirstClass_Str(self);

}

static PyObject* FirstClass_Name(FirstClass* self){

	return Py_BuildValue("s",self->m_PlayerName);
	
}
static PyObject* FirstClass_ID(FirstClass* self){

	return Py_BuildValue("l",self->m_PlayerID);
	
}

static PyObject* FirstClass_SetName(FirstClass* self,PyObject* pArgvs){
	Py_INCREF(Py_None);
	const char* Name;
	if(!PyArg_ParseTuple( pArgvs,"s",  &Name ) ){
		return Py_None;
	}
	if (self->m_PlayerName){
		delete[] self->m_PlayerName;
		self->m_PlayerName = NULL;
	}
	self->m_PlayerName = new char[strlen(Name) + 1];
	strcpy(self->m_PlayerName,Name);
	return Py_None;  
}


static PyMemberDef FirstClass_DataMembers[] = {
	{"m_PlayerName",T_STRING,offsetof(FirstClass,m_PlayerName),0,"The Name of PlayerObj"},
	{"m_PlayerID",T_ULONG,offsetof(FirstClass,m_PlayerID),0,"The ID of PlayerObj"},
	{NULL,NULL,0,NULL},
};

static PyMethodDef FirstClass_MethodMembers[] = {

	{"Name",(PyCFunction)FirstClass_Name,METH_NOARGS,"Name of Player"},
	{"ID",(PyCFunction)FirstClass_ID,METH_NOARGS,"ID of Player"},
	{"SetName",(PyCFunction)FirstClass_SetName,METH_VARARGS,"set player name"},
	{NULL,NULL,NULL,NULL}
};

static PyTypeObject FirstClass_ClassInfo =  
{  
       PyVarObject_HEAD_INIT(NULL, 0)
	   "Module.MyCppClass",                 //可以通过__class__获得这个字符串. CPP可以用类.__name__获取.  
       sizeof(FirstClass),                 //类/结构的长度.调用PyObject_New时需要知道其大小.  
       0,  
       (destructor)FirstClass_Destruct,	//类的析构函数
       0,  
       0,  
       0,  
       0,  
       (reprfunc)FirstClass_Repr,			//repr 内置函数调用。  
        0,  
       0,  
       0,  
       0,  
       0,  
       (reprfunc)FirstClass_Str,          //Str/print内置函数调用.  
       0,  
       0,  
       0,  
       Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                 //如果没有提供方法的话，为Py_TPFLAGS_DEFAULE  
       "MyCppClass Objects---Extensioned by C++!",                   //__doc__,类/结构的DocString.  
       0,  
       0,  
       0,  
       0,  
       0,  
       0,  
       FirstClass_MethodMembers,        //类的所有方法集合.  
       FirstClass_DataMembers,          //类的所有数据成员集合
       0,  
       0,  
       0,  
       0,  
       0,  
       0,  
       (initproc)FirstClass_init,      //类的构造函数.  
       0,  
};  

yMODINIT_FUNC
init_msi(void)
{
    PyObject *m;

    m = Py_InitModule3("_msi", msi_methods, msi_doc);
    if (m == NULL)
        return;

    PyModule_AddIntConstant(m, "MSIDBOPEN_CREATEDIRECT", (int)MSIDBOPEN_CREATEDIRECT);
    PyModule_AddIntConstant(m, "MSIDBOPEN_CREATE", (int)MSIDBOPEN_CREATE);
    PyModule_AddIntConstant(m, "MSIDBOPEN_DIRECT", (int)MSIDBOPEN_DIRECT);
    PyModule_AddIntConstant(m, "MSIDBOPEN_READONLY", (int)MSIDBOPEN_READONLY);
    PyModule_AddIntConstant(m, "MSIDBOPEN_TRANSACT", (int)MSIDBOPEN_TRANSACT);
    PyModule_AddIntConstant(m, "MSIDBOPEN_PATCHFILE", (int)MSIDBOPEN_PATCHFILE);

    PyModule_AddIntConstant(m, "MSICOLINFO_NAMES", MSICOLINFO_NAMES);
    PyModule_AddIntConstant(m, "MSICOLINFO_TYPES", MSICOLINFO_TYPES);

    PyModule_AddIntConstant(m, "MSIMODIFY_SEEK", MSIMODIFY_SEEK);
    PyModule_AddIntConstant(m, "MSIMODIFY_REFRESH", MSIMODIFY_REFRESH);
    PyModule_AddIntConstant(m, "MSIMODIFY_INSERT", MSIMODIFY_INSERT);
    PyModule_AddIntConstant(m, "MSIMODIFY_UPDATE", MSIMODIFY_UPDATE);
    PyModule_AddIntConstant(m, "MSIMODIFY_ASSIGN", MSIMODIFY_ASSIGN);
    PyModule_AddIntConstant(m, "MSIMODIFY_REPLACE", MSIMODIFY_REPLACE);
    PyModule_AddIntConstant(m, "MSIMODIFY_MERGE", MSIMODIFY_MERGE);
    PyModule_AddIntConstant(m, "MSIMODIFY_DELETE", MSIMODIFY_DELETE);
    PyModule_AddIntConstant(m, "MSIMODIFY_INSERT_TEMPORARY", MSIMODIFY_INSERT_TEMPORARY);
    PyModule_AddIntConstant(m, "MSIMODIFY_VALIDATE", MSIMODIFY_VALIDATE);
    PyModule_AddIntConstant(m, "MSIMODIFY_VALIDATE_NEW", MSIMODIFY_VALIDATE_NEW);
    PyModule_AddIntConstant(m, "MSIMODIFY_VALIDATE_FIELD", MSIMODIFY_VALIDATE_FIELD);
    PyModule_AddIntConstant(m, "MSIMODIFY_VALIDATE_DELETE", MSIMODIFY_VALIDATE_DELETE);

    PyModule_AddIntConstant(m, "PID_CODEPAGE", PID_CODEPAGE);
    PyModule_AddIntConstant(m, "PID_TITLE", PID_TITLE);
    PyModule_AddIntConstant(m, "PID_SUBJECT", PID_SUBJECT);
    PyModule_AddIntConstant(m, "PID_AUTHOR", PID_AUTHOR);
    PyModule_AddIntConstant(m, "PID_KEYWORDS", PID_KEYWORDS);
    PyModule_AddIntConstant(m, "PID_COMMENTS", PID_COMMENTS);
    PyModule_AddIntConstant(m, "PID_TEMPLATE", PID_TEMPLATE);
    PyModule_AddIntConstant(m, "PID_LASTAUTHOR", PID_LASTAUTHOR);
    PyModule_AddIntConstant(m, "PID_REVNUMBER", PID_REVNUMBER);
    PyModule_AddIntConstant(m, "PID_LASTPRINTED", PID_LASTPRINTED);
    PyModule_AddIntConstant(m, "PID_CREATE_DTM", PID_CREATE_DTM);
    PyModule_AddIntConstant(m, "PID_LASTSAVE_DTM", PID_LASTSAVE_DTM);
    PyModule_AddIntConstant(m, "PID_PAGECOUNT", PID_PAGECOUNT);
    PyModule_AddIntConstant(m, "PID_WORDCOUNT", PID_WORDCOUNT);
    PyModule_AddIntConstant(m, "PID_CHARCOUNT", PID_CHARCOUNT);
    PyModule_AddIntConstant(m, "PID_APPNAME", PID_APPNAME);
    PyModule_AddIntConstant(m, "PID_SECURITY", PID_SECURITY);

    MSIError = PyErr_NewException ("_msi.MSIError", NULL, NULL);
    if (!MSIError)
        return;
    PyModule_AddObject(m, "MSIError", MSIError);
}



int main(int argc,char* argv[]){
	
	


	return 0;
}







