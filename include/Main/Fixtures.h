#define SLIM_QUOTES(x)  #x
void StatementExecutor_AddFixture(void*, void*);
void StatementExecutor_RegisterFixture(void*, void *, void *, void *);
void StatementExecutor_RegisterMethod(void*, void * , void *, void *);
void StatementExecutor_ConstructorError(void *, char *);

#define SLIM_FIXTURE(fixture) \
extern void fixture##_Register(void*);\
StatementExecutor_AddFixture(executor, fixture##_Register); 

#define SLIM_FIXTURES void AddFixtures(void* executor) \
{

#define SLIM_END }


#define SLIM_CREATE_FIXTURE(name) static char * fixtureName = #name; \
void name##_Register(void* executor) \
{ \
	StatementExecutor_RegisterFixture(executor, #name, name##_Create, name##_Destroy);
#define SLIM_FUNCTION(name) StatementExecutor_RegisterMethod(executor, fixtureName, #name, name);	


#define SLIM_ABORT(reason) SLIM_QUOTES(__EXCEPTION__:ABORT_SLIM_TEST:message:<<reason.>>)

#define SLIM_EXCEPTION(reason) SLIM_QUOTES(__EXCEPTION__:message:<<reason.>>)

#define SLIM_CONSTRUCTOR_ERROR(errorHandler, reason) 		StatementExecutor_ConstructorError(errorHandler, reason);

