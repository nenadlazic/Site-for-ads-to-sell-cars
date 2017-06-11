<?php 
	function drawContent()
	{
		echo "	
			<div id='sadrzaj'>	";
			
			//################################################################################################################
			//forma za pretragu
			//################################################################################################################			
			
			echo "
				<div id='pretraga'>
					<form action='' method='post' name='pretraga' onsubmit='return proveriFormuPretrage();'>
						<label for='MARKA'>Marka</label><br/>
							<select name='proizvodjac'>
								<option selected='selected'>Izaberi marku</option>
								<option value='alfa romeo'>Alfa Romeo</option>
								<option value='audi'>Audi</option>
								<option value='bentley'>Bentley</option>
								<option value='bmw'>BMW</option>
								<option value='dacia'>Dacia</option>
								<option value='daewoo'>Daewoo</option>
								<option value='ferari'>Ferari</option>
								<option value='fiat'>Fiat</option>
								<option value='ford'>Ford</option>
								<option value='honda'>Honda</option>
								<option value='hyundai'>Hyundai</option>
								<option value='jaguar'>Jaguar</option>
								<option value='lancia'>Lancia</option>
								<option value='lexus'>Lexus</option>
								<option value='mercedes benz'>Mercedes benz</option>
								<option value='opel'>Opel</option>
								<option value='peugeot'>Peugeot</option>
								<option value='skoda'>Škoda</option>
								<option value='volkswagen'>Volkswagen</option>
								<option value='zastava'>Zastava</option>
							</select>
							
						<br/>
						
						<label for='KAROSERIJA'>Karoserija</label><br/>
							<select name='karoserija'>
								<option selected='selected'>Izaberi karoseriju</option>
								<option>Limuzina</option>
								<option>Hečbek</option>
								<option>Karavan</option>
								<option>Kupe</option>
								<option>Kabriolet/Rodster</option>
								<option>Monovolumen(MiniVan)</option>
								<option>Džip/SUV</option>
								<option>Pick up</option>
							</select>
							
						<br/>
						
						
						<label for='KUBIKAZA'> Kubikaža </label><br/>
						Od:<select name='kubikaOd'>
							<option selected='selected'>od</option>
							<option>500</option>
							<option>600</option>
							<option>700</option>
							<option>800</option>
							<option>900</option>
							<option>1000</option>
							<option>1100</option>
							<option>1200</option>
							<option>1300</option>
							<option>1400</option>
							<option>1500</option>
							<option>1600</option>
							<option>1700</option>
							<option>1800</option>
							<option>1900</option>
							<option>2000</option>
							<option>2500</option>
						</select>
						
						
						Do:<select name='kubikaDo'>
							<option selected='selected'>do</option>
							<option>600</option>
							<option>700</option>
							<option>800</option>
							<option>900</option>
							<option>1000</option>
							<option>1100</option>
							<option>1200</option>
							<option>1300</option>
							<option>1400</option>
							<option>1500</option>
							<option>1600</option>
							<option>1700</option>
							<option>1800</option>
							<option>1900</option>
							<option>2000</option>
							<option>2500</option>
							<option>3000</option>
						</select>
					
						<br/>
						
						<label for='GODISTE'> Godište </label><br/>
							Od:<select name='godisteOd'>
								<option selected='selected'>od</option>";
								
								for($i = 1970; $i <2015; $i++)
								{
									echo " <option>".$i."</option>";
								}
							echo "</select>";

							echo "
							Do:<select name='godisteDo'>
							<option selected='selected'>do</option>
							";
							
							for($i = 1971; $i <2015; $i++)
							{
								echo "<option>".$i."</option>";
							}
							echo "</select> 
							<br/>";
							
						echo "<label for='CENA'> Cena </label>
							<br/>
							<input type='text' name='cenaOd' value='od' size='5' onclick='ukloniInicijalniTekst1();' onblur='postaviInicijalniTekst1()'/>€
							<input type='text' name='cenaDo' value='do' size='5' onclick='ukloniInicijalniTekst2();' onblur='postaviInicijalniTekst2()'/>€
							<br/>
						";
						
						
						
						echo "
						<label for='REGION'> Region </label><br/>
							<select name='region'>
								<option selected='selected'>Izaberi region</option>
								<option>Centralna Srbija</option>
								<option>Istočna Srbija</option>
								<option>Južna Srbija</option>
								<option>Kosovo i Metohija</option>
								<option>Vojvodina</option>
								<option>Zapadna Srbija</option>
							</select>
						
						<br/>
						
						<label for='GORIVO'>Gorivo</label><br/>
							Dizel <input type='radio' name='gorivo' value='dizel' checked='checked'/>
							Benzin <input type='radio' name='gorivo' value='benzin'/>
							Gas <input type='radio' name='gorivo' value='gas'/>
						<br/>
						
						<label for='REGISTROVAN'> Registrovano vozilo: </label><br/>
							<input type='checkbox' name='registrovan' id='registrovannno' value='da' />da <br/>
							<input type='checkbox' name='neregistrovan' id='neregistrovannno' value='ne'/>ne
						<br/>
						<input type='submit' name='pretrazi' value='Pretraži' />
						<input type='reset' name='ponisti' value='Poništi'/>
						
						";
						
					echo "</form>
				</div>
				";
				
				//################################################################################################################
				//kraj forme za pretragu i pocetak sekcije za poslednje postavljene oglase
				//################################################################################################################

					// <div id='oglas1' class='oglas'>
					// </div>
					// <div id='oglas2' class='oglas'>
					// </div>
					// <div id='oglas3' class='oglas'>
					// </div>
					// <div id='oglas4' class='oglas'>
					// </div>
					// <div id='oglas5' class='oglas'>
					// </div>


				
				echo "
				<div id='zadnjiOglasi'>
					<p id='pozdravnaPoruka'> Dobrodošli na sajt autooglasi.rs</p>
					<p id='pozdravniTekst'> Na našem sajtu možete pronaći auto po meri vaših kriterijuma koristeći detaljnu pretragu oglasa ili potpuno besplatno 
						ostaviti jedan oglas na našem sajtu. Potrebno vam je samo nekoliko trenutaka da se registrujete.<br/> Hvala vam što posećujete autooglasi.rs</p>
				</div>
				
				<div id='log' name='divZaCrtanjeLoginLogout'>
					<form method='post' name='logovanje' onsubmit='return proveriFormuLogovanja();'>
						Ulogujte se:<br/>
						Username:<br/>
						<input type='text' name='username' value='ovde unesite username' onclick='ukloniInicijalniTekst3();' onblur='postaviInicijalniTekst3()'/><br/>
						Password:<br/>
						<input type='password' name='sifra'/><br/>
						<input type='submit' name='login' value='uloguj se'/>
					</form>
				</div>
				
				<br/>
				<div class='korisniLinkovi'>
					
					<ul>
						<li class='bezSquare'> Korisni linkovi: </li>
						<li> <a href='http://www.polovniautomobili.com/'>polovniautomobili.com</a> </li> 
						<li> <a href='http://www.mojauto.rs/'>mojauto.rs</a> </li> 
						<li> <a href='http://mojagaraza.rs/'>mojagaraza.rs</a> </li> 
						<li> <a href='http://www.pik.ba/'>pik.ba</a> </li> 
						<li> <a href='http://www.kupujemprodajem.com/'>kupujemprodajem.com</a> </li> 
						<li> <a href='http://www.webauto.de/'> webauto.de </a></li> 
						<li> <a href='http://www.autotrader.co.uk/'>autotrader.co.uk</a> </li> 
						<li> <a href='http://www.car4you.ch/'>car4you.ch</a> </li> 
					</ul>
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
			</div>";
	}

?>