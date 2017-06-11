<?php 
	function dravRegistration()
	{
		echo "
			<div id='registrovanje'>
				<div id='oreg'>
					<p id='uvod'>
						Registracija novog korisnika na www.autooglasi.com<br/><br/>
						Kako biste se registrovali potrebno je popuniti formular za registraciju. Registracija je 
						besplatna i jednostavna, a oduzeće vam svega par minuta. Nakon što se registrujete možete postaviti
						oglas za prodaju vašeg automobila.
					</p>
					
					<form action='upis_u_bazu_registracija.php' method='post' name='registrovanjeNaSajt' onsubmit='return proveriFormuRegistracije();'>
						<table>
							<tr>
								<td> ime: </td> <td> <input type='text' name='imeKorisnika'/> </td> <td></td>
							</tr>
							<tr>
								<td> prezime: </td> <td> <input type='text' name='prezimeKorisnika'/> </td> <td></td>
							</tr>
							<tr>
								<td> ime na sajtu:</td> <td> <input type='text' name='imeNaSajtu'/> </td> <td id='imeNaSajtuu'>*obavezno polje</td>
							</tr>
							<tr>
								<td> e-mail:</td> <td> <input type='email' name='emailKorisnika'/> </td> <td>*obavezno polje</td>
							</tr>
							
							<tr>
								<td> password: </td> <td><input type='password' name='sifrica'/></td> <td>*obavezno polje</td>
							</tr>
							<tr>
								<td>confirm password: </td><td><input type='password' name='sifricaOpet'/></td> <td>*obavezno polje</td>
							</tr>
												
							<tr>
								<td colspan='2'><p style='font-size:12px'>*Šifra mora sadržati od 6 do 20 karaktera </p> </td>
							</tr>
							<tr>
								<td>&nbsp;</td>
								<td><input type='submit' name='registracijaSubmit' value='Registruj se'/></td> <!--postavljen atribut onaction -->
						</table>
					</form>
				</div>

				<div class = 'logoZnaci'>
					 <a href='http://www.vw-club.rs/forum/'> <img src='slike/logovw.jpg' alt='volkswagen' class='logo'/> </a>
					 <a href='http://www.bmwclubserbia.com/forum/index.php?act=idx'> <img src='slike/logobmw.jpg' alt='volkswagen' class='logo'/> </a>
					 <a href='http://audiclubserbia.com/forum/'> <img src='slike/logoaud.jpg' alt='volkswagen' class='logo'/> </a>
					 <a href='http://www.chevroletforumserbia.com/'> <img src='slike/logoche.jpg' alt='volkswagen' class='logo'/> </a>
					 <a href='http://arcs.org.rs/forum/'> <img src='slike/logoar.jpg' alt='volkswagen' class='logo'/> </a>
					 <a href='http://www.cadillacforums.com/'> <img src='slike/logocad.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.jaguarforums.com/forum/'><img src='slike/logojag.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.mazdaclub.rs/forum/'><img src='slike/logoma.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://forumsrbija.toyotaadria.com/'><img src='slike/logotoy.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://dodgeforum.com/'><img src='slike/logodod.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.fordclubserbia.org/forum/viewforum.php?f=3'><img src='slike/logoford.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://porsche.freeforums.net/'><img src='slike/logoporshe.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.suzuki-forums.com/'><img src='slike/logosuzuki.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.hondaclub.rs/forum/'><img src='slike/logohonda.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.volvoklubsrbija.rs/'><img src='slike/logovolvo.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.6speedonline.com/forums/aston-martin-39/'><img src='slike/logoaston.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.6speedonline.com/forums/aston-martin-39/'><img src='slike/logochr.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.lamborghini-talk.com/'><img src='slike/logolam.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.peugeotcafe.com/'><img src='slike/logopezo.jpg' alt='volkswagen' class='logo'/></a>
					 <a href='http://www.mercedesklub.rs/'><img src='slike/logomer.jpg' alt='volkswagen' class='logo'/></a>
				</div>
			</div>
		";
		}
?>