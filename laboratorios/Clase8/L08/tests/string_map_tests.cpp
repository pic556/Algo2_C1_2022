TEST(string_map_test, values) {
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios",  3));

    con_prefijos.insert(make_pair("c",  1));
    con_prefijos.insert(make_pair("casa",  2));
    con_prefijos.insert(make_pair("casona",  3));

    for (int* i : sin_prefijos.values()) {
        cout << *i << " ";
    }

    cout << endl;

    for (int* i : con_prefijos.values()) {
        cout << *i << " ";
    }
    cout << endl;
}