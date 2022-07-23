template <class T>
std::set<T*> string_map<T>::values() {
    return valuesAux(raiz);
}

template <class T>
std::set<T*> string_map<T>::valuesAux(Nodo* nodo) {
    std::set<T*> ans;
    if (nodo->definicion != nullptr) {
        ans.insert(nodo->definicion);
    }
    for (Nodo* sig : nodo->siguientes) {
        if (sig != nullptr) {
            for (T* def: valuesAux(sig)) {
                ans.insert(def);
            }
        }
    }
    return ans;
}