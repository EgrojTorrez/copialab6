#pragma once
#include "../../motor/KeyOyente.hpp"
#include "../../motor/MouseOyente.hpp"
#include "../../motor/camaras/Camaras.hpp"
#include "../Estructuras.hpp"
#include<string>

class Camara; //declaración circular

class FSMCamara
{
    protected:
        float vel;
        Coordenadas pos_final;
        Coordenadas pos_inicial;
        int frames_actual;
        int frames_maximo;
    public:
        std::string strestado;
    public:
        virtual ~FSMCamara(){};
        virtual FSMCamara* input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse)=0;
        virtual void on_entrar(Camara &cam)=0;
        virtual void on_salir(Camara &cam)=0;
        virtual void on_update(Camara &cam)=0;
};

class EstadoCamaraMover : public FSMCamara
{
    public:
        EstadoCamaraMover(Coordenadas dir);
        virtual ~EstadoCamaraMover(){};
        FSMCamara* input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        Coordenadas direccion;

};

//PARA USAR LERP
class EstadoCamaraTransicion : public FSMCamara
{
    public:
        EstadoCamaraTransicion();
        virtual ~EstadoCamaraTransicion(){};
        FSMCamara* input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        Coordenadas check;
        Coordenadas ant_check;
        float diff =0.10; //10 puntos por linea(1/diff)
        float u= 0;
};

class EstadoCamaraLock : public FSMCamara
{
    public:
        EstadoCamaraLock(Objeto &objlock);
        virtual ~EstadoCamaraLock(){};
        FSMCamara* input_handle(Camara &cam, KeyOyente &keys, MouseOyente& mouse);
        void on_entrar(Camara &cam);
        void on_salir(Camara &cam);
        void on_update(Camara &cam);
    private:
        Coordenadas centro;
        Objeto *obj;

};