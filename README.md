Averko C++ kurssin lopputyö 14.7.2022

Matopeli

Peetu Puikkonen

Tampereen Ammattikorkeakoulu Tamk

Sähkö- ja automaatiotekniikka

Tein kurssin lopputyönä Matopelin, joka muistuttaa paljolti vanhan Nokia 3310-puhelimen Snake II:sta.
Matoa ohjataan näppäimillä WASD. Syödessä "hedelmän", madon koko kasvaa yhdellä. Madon on mahdollista kulkea seinien läpi, jolloin madon pää ilmestyy vastakkaiselle seinälle ruumiin kulkiessa mukana. Syödessään hedelmän, pistemäärä kasvaa 10:llä. Peli päättyy, jos madon pää törmää ruumiiseen.

Pelin teossa käytettiin useita kurssilla opittuja tekniikoita. Minulla oli hiukan kokemusta C/C++ aikaisemmalta Arduino-kurssilta, joka auttoi myös tämän koodin teossa.
Tietenkin paljon joutui asioita googlaamaan, mutta niinhän se yleensä menee koodausmaailmassa. Pelin käyttöliittymänä toimii komentorivi, johon grafiikka tulostetaan.

Koodin alussa esitellään useampi eri muuttuja, joita tarvitaan tulevissa funktioissa. Tämän jälkeen esitellään funktiot:
1. menu()-funktiossa kutsutaan intro-luokka, joka tulostaa käyttöliittymään aloitustekstit. Tässä pelaaja voi päättää aloittaako pelin vai sulkeeko käyttöliittymän.
2. Asetukset()-funktiossa määritetään madon aloituspaikka kentällä (keskellä) sekä annetaan stop-komento, ettei mato lähde itsestään liikkeelle peliä aloittaessa. Tämän lisäksi funktiossa hedelmän paikka asetetaan satunnaisesti pelikentälle. Myös kentän bufferointi tehdään tässä funktiossa (poistaa komentorivin "välkynnän" joka johtuu jatkuvasta tulostuksen putsauksesta.
3. grafiikanPiirto()-funktio nimensä mukaisesti piirtää (eli tulostaa) pelikentän reunat (jokainen erikseen), madon pään ja hännän sekä hedelmän sekä pistemäärän. Näiden lisäksi funktio suorittaa grafiikan jatkuvaa "puhdistusta" joka poistaa madon (ja hedelmän) edellisen paikan kentällä sen liikkuessa. 
4. Ohjaus()-funktiossa määritetään näppäimet madon ohjaukselle. Pelissä ohjaukseen käytetään näppäimiä WASD. Funktiossa estetään myös madon liikkuminen täysin päinvastaiseen suuntaan mihin se on menossa (eli jos mennään oikealla, estetään suunta suoraan vasemmalle jne). 
5. Logiikka()-funktiossa määritetään ruumiin liikkuminen pään mukana. Funktio pitää jatkuvasti tiedossa pään edellistä paikkaa pelikentällä, ja tulostaa ruumiin/hännän kyseiselle paikalle. Logiikka-funktiossa myös määritetään pään liikkuminen näppäinten mukaan. MatoX ja Y muuttujat kasvavat/laskevat riippuen siitä, mitä suuntanäppäintä pelaaja painaa. Lisäksi funktiossa mahdollistetaan madon liikkuminen seinien läpi hännän seuratessa, uuden hedelmän arpominen kentälle (ja samalla estetään ettei hedelmä voi vahingossa tulostua madon sisään!), pistemäärän että hännän kasvu.
Lopuksi tulee tietty main()-funktio, jossa käydään vielä pari komentoa (mm. uuden random_seedin luonti käyttäen tietokoneen sisäistä kelloa, tämä mahdollistaa täysin satunnaisen hedelmän arpomisen kentälle joka kerta) ja kutsutaan ylläolevia funktioita.

Lopputyö on mielestäni onnistunut ja olen tyytyväinen suoritukseen. Työ oli sopivan haastava ja suurimpia ongelmia oli grafiikan piirto ja hännän liikkuminen pään mukana varsinkin kun mennään pelikentän reunan läpi vastakkaiselle puolelle. Peliä olisi mahdollista kehittää vielä vaikka kuinka paljon jos aikaa olisi, esimerkiksi lisä-asetuksia voisi liittää peliin joita pelaaja voisi muuttaa käyttöliittymässä ennen pelin aloitusta mm. madon nopeus (tosin löytyy jo koodista main()-funktiossa (speed(70), mutta tämä vaatii arvon muuttamista suoraan koodissa) ja vaikka pelaajan mukaan valittava pelikentän reunojen toiminto (mato voi mennä läpi/mato törmää ja peli päättyy (tämäkin toiminto löytyy koodista ulos-kommentoituna)). Myös "kunnollisen" grafiikan liittäminen peliin toisi varmasti hienomman säväyksen sen sijaan että käytetään komentoriviin tulostettuja symboleja. Mutta itse pelin pääidea toimii hyvin ja koodin toiminnallisuus oli tämän lopputyön tärkein tavoite.
