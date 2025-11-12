#include "RedSocial.h"
#include <iostream>
using namespace std;

RedSocial::RedSocial(){
   _usuarios = {};
     _id_alias = {}:
    alias_a_id={};
    _friends = {};
    _conocidos = {};
     _cantidad_amistades = 0;
}

const set<int> & RedSocial::usuarios() const{
    return _usuarios; // O(1)
}
string RedSocial::obtener_alias(int id) const{
    return _id_alias[id]; // O(log n)
}
const set<string> & RedSocial::obtener_amigos(int id) const{
    return _friends[id]; //O(log n)
}

const set<string> & RedSocial::obtener_conocidos(int id) const{
    return _conocidos[id]; //O(log n)
}
int RedSocial::cantidad_amistades() const{
    return _cantidad_amistades; //O(1)
}

void RedSocial::registrar_usuario(string alias, int id){
    id_a_alias[id] = alias;
    alias_a_id[alias] = id;
    _usuarios.insert(id);
    _friends = {};
    _conocidos[id] = {};
}

void RedSocial::eliminar_usuario(int id){
    id_a_alias.erase(id);
    _friends.erase(id);
    _conocidos.erase(id);
    _usuarios.erase(id);

}

void RedSocial::amigar_usuarios(int id_A, int id_B){
    string aliasA = _id_alias[id_A];
    string aliasB = _id_alias[id_B];
    _friends[id_A].insert(aliasB);
    _friends[id_B].insert(aliasA);
    _cantidad_amistades = _cantidad_amistades +1;
}

void RedSocial::desamigar_usuarios(int id_A, int id_B){
    // restar 1 
    string aliasA = _id_alias[id_A];
    string aliasB = _id_alias[id_B];
    _friends[id_A].erase(aliasB);
    _friends[id_B].erase(aliasA);
    total_amistades--;
}

int RedSocial::obtener_id(string alias) const{
    return alias_a_id[alias]; // O(1) en promedio por el unorded map
}
const set<string> & RedSocial::conocidos_del_usuario_mas_popular() const{
}

 