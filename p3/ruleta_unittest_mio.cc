#include "gtest/gtest.h"
#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"

TEST (Ruleta, Constructor) {
    Crupier c("dni1", "code1");
    Ruleta r(c);

    EXPECT_EQ(-1, r.getBola());
    EXPECT_EQ(1000000, r.getBanca());
    EXPECT_EQ("dni1", r.getCrupier().getDNI());
    EXPECT_EQ("code1", r.getCrupier().getCodigo());
}

TEST (Ruleta, GetSetBola) {
    Crupier c("dni1", "code1");
    Ruleta r(c);

    EXPECT_TRUE(r.setBola(10));
    EXPECT_EQ(10, r.getBola());

    EXPECT_FALSE(r.setBola(-1));
    EXPECT_EQ(10, r.getBola());
    
    EXPECT_FALSE(r.setBola(80));
    EXPECT_EQ(10, r.getBola());
}

TEST (Ruleta, GetSetCrupier) {
    Crupier c1("dni1", "code1");
    Crupier c2("dni2", "code2");
    Ruleta r(c1);

    r.setCrupier(c2);

    EXPECT_EQ("dni2", r.getCrupier().getDNI());
    EXPECT_EQ("code2", r.getCrupier().getCodigo());
}

TEST (Ruleta, AddGetJugadores) {
    Crupier c("dni", "code");
    Ruleta r(c);

    Jugador j[10];
    for (int i = 0; i < 10; i++) {
        j[i] = Jugador("dni" + i, "code" + i);
        EXPECT_TRUE(r.addJugador(j[i]));
    }

    std::list<Jugador> jugadores;
    jugadores = r.getJugadores();

    int count = 0;
    for (Jugador j : jugadores) {
        EXPECT_EQ("dni" + count, j.getDNI());
        EXPECT_EQ("code" + count, j.getCodigo());
        count++;
    }
}

TEST (Ruleta, ) {

}