

bigint* fac(lie_Index n);

bigint* n_tableaux(entry* lambda, lie_Index l);

bigint* Classord(entry* kappa, lie_Index l);

lie_Index check_part(entry* lambda, lie_Index l);

vector* check_tabl(vector* v);

boolean Nextperm(entry* w, lie_Index n);

boolean Nextpart(entry* lambda, lie_Index l);

boolean Nexttableau(entry* t, lie_Index n);

matrix* Permutations(entry* v,lie_Index n);

matrix* Partitions(lie_Index n);

matrix* Tableaux(entry* lambda, lie_Index l);

vector* Trans_part(entry* lambda, lie_Index l);

entry Sign_part(entry* lambda, lie_Index l);

void Robinson_Schensted (entry* P, entry* Q, lie_Index n, entry* sigma);

void Schensted_Robinson (entry* sigma, lie_Index n, entry* P, entry* Q);

poly* MN_char(entry* lambda, lie_Index l);

bigint* MN_char_val(entry* lambda, entry* mu, lie_Index l, lie_Index m);


