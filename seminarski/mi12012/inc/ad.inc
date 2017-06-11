<?php 
	function dravAd()
	{
		echo "

			<div id='oglas'>
				<div id='upuststvoZaPostavljanjeOglasa'>
					Popunite što više podataka, kako bi oglas bio vidljiviji u pretrazi. <br/> Polja obeležena sa * su obavezna polja.<br/> 
					Fizička lica koja žele da oglase lično vozilo mogu besplatno postaviti po jedan oglas.<br/> Oglasi novih korisnika pre objavljivanja na sajtu prolaze kontrolu od strane administratora, dok će ostali oglasi biti objavljeni odmah, ali prolaze naknadnu kontrolu.<br/> Oglasi koji nisu u skladu sa uslovima korišćenja biće izbrisani.<br/> Dodatni i istaknuti oglasi se naplaćuju.<br/> 
				</div>";

				include('inc/db.inc'); //povezujemo se sa bazom
				//proveravamo da li korisnik vec ima aktivan oglas (u tom slucaju moze samo da ga promeni)
				//ako korisnik nema aktivne oglase moze da postavi oglas


					if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) {
						$trenutno_ulogovani = $_SESSION['username']; //ocitavamo ulogovanom korisnika
						$trenutno_ulogovani = $trenutno_ulogovani."o1"; //dodajemo sufiks-objasnjenje u tekstu opis.txt
						$query = "SELECT * FROM oglasi WHERE idOglasa='$trenutno_ulogovani'"; //proveravamo da li je vec postavio oglas
					    $result = mysqli_query($veza, $query) or die(mysqli_error());
					    $num = mysqli_num_rows($result);
					    mysqli_close($veza);

				    if($num > 0){
				    	//echo "Editovanje oglasa";
				    	ispisi_formu_za_oglas_edit();
				    	//ovde dodati kod kojim bi citali podatke iz baze i upisivali u formu kako bi korisnik video podatke koje je vec upisao
				    }
				     else{
				     	//echo "Postavljanje oglasa";
				     	ispisi_formu_za_oglas();
				     	}				
				}
				else
				{
					ispisi_formu_za_oglas();
					echo "
			            <script type='text/javascript'>
			                window.alert('Potrebno je da se ulogujete.');
			            </script>
			            ";
			           // echo "iz neulogovanog";
				}
			}

	function ispisi_formu_za_oglas(){
				echo "<div id='og1'>
					<!--forma za postavljanje oglasa-->
					<p> Ovde možete postaviti vaš oglas za prodaju automobila </p>

					<form onaction='' enctype='multipart/form-data' method = 'post' name='formaZaUpisOglasaUbazuPodataka' onsubmit='return proveriFormuUpisa();' >
						<table>
							<tr><th>Marka automobila: </th>
								<td>
									<select name='proizvodjacc'>
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
								</td>
							</tr>
							<tr>
								<th>Karoserija: </th>
								<td>
									<select name='karoserijaa'>
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
								</td>
							</tr>
							<tr>
								<th>Kubikaža:</th>
								<td>
									<input type='number' name='kubikaa'>
								</td>
							</tr>
							<tr>
								<th>Godište:</th>
								<td><input type='number' name='godistee'></td>
							</tr>
							<tr>
								<th>Cena:</th>
								<td><input type='number' name='cenaa'></td>
							</tr>						
							<tr>
								<th>Region: </th>
								<td>
									<select name='regionn'>
										<option selected='selected'>Izaberi region</option>
										<option>Centralna Srbija</option>
										<option>Istočna Srbija</option>
										<option>Južna Srbija</option>
										<option>Kosovo i Metohija</option>
										<option>Vojvodina</option>
										<option>Zapadna Srbija</option>
									</select>								
								</td>
							</tr>	
							<tr>
								<th> Gorivo: </th>
								<td>
									Dizel <input type='radio' name='gorivoo' value='dizel' checked='checked'/>
									Benzin <input type='radio' name='gorivoo' value='benzin' />
									Gas <input type='radio' name='gorivoo' value='gas'/>
								</td>
							</tr>							
							<tr>
								<th>Registrovan: </th>
								<td>
									<input type='checkbox' name='registrovann' value='da' checked='checked'/>da
									<input type='checkbox' name='neregistrovann' value='ne'/>ne
								</td>
							</tr>
							<tr>
								<th>Tekst oglasa: </th>
								<td>
									<textarea rows='3' cols='20' name='oglasTekstic' maxlength='200'></textarea>
								</td>
							</tr>
							<tr>
								<th>Telefon: </th><td><input type='number' name='brTelefona'/></td>
							</tr>
							<tr><th>Slika: </th><td> <input type='file' value='Odaberi sliku' name='image' id='fileSlikaOglasa' accept='image/*'/></td></tr>";

							if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) 
								echo "<tr> <th></th><td> <input type='submit' name = 'upisiOglasUbazu' value='Postavi oglas'/> </td></tr>";

						echo "
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
							//echo "trenutno je ulogovan ".$_SESSION['username'];
		}



	function ispisi_formu_za_oglas_edit(){
				echo "<div id='og1'>
					<!--forma za editovanje oglasa-->
					<p> Ovde možete promeniti vaš oglas za prodaju automobila </p>

					<form onaction='' enctype='multipart/form-data' method = 'post' name='formaZaIzmenuOglasa'>
						<table>
							<tr><th>Marka automobila: </th>
								<td>
									<select name='proizvodjaccc'>
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
								</td>
							</tr>
							<tr>
								<th>Karoserija: </th>
								<td>
									<select name='karoserijaaa'>
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
								</td>
							</tr>
							<tr>
								<th>Kubikaža:</th>
								<td>
									<input type='number' name='kubikaaa'>
								</td>
							</tr>
							<tr>
								<th>Godište:</th>
								<td><input type='number' name='godisteee'></td>
							</tr>
							<tr>
								<th>Cena:</th>
								<td><input type='number' name='cenaaa'></td>
							</tr>						
							<tr>
								<th>Region: </th>
								<td>
									<select name='regionnn'>
										<option selected='selected'>Izaberi region</option>
										<option>Centralna Srbija</option>
										<option>Istočna Srbija</option>
										<option>Južna Srbija</option>
										<option>Kosovo i Metohija</option>
										<option>Vojvodina</option>
										<option>Zapadna Srbija</option>
									</select>								
								</td>
							</tr>	
							<tr>
								<th> Gorivo: </th>
								<td>
									Dizel <input type='radio' name='gorivooo' value='dizel' checked='checked'/>
									Benzin <input type='radio' name='gorivooo' value='benzin' />
									Gas <input type='radio' name='gorivooo' value='gas'/>
								</td>
							</tr>							
							<tr>
								<th>Registrovan: </th>
								<td>
									<input type='checkbox' name='registrovannn' value='da' checked='checked'/>da
									<input type='checkbox' name='neregistrovannn' value='ne'/>ne
								</td>
							</tr>
							<tr>
								<th>Tekst oglasa: </th>
								<td>
									<textarea rows='3' cols='20' name='oglasTeksticc' maxlength='200'></textarea>
								</td>
							</tr>
							<tr>
								<th>Telefon: </th><td><input type='text' name='brTelefonaa'/></td>
							</tr>
							<tr><th>Slika: </th><td> <input type='file' value='Odaberi sliku' name='imagee' id='fileSlikaOglasaa' accept='image/*'/></td></tr>";

							if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) 
								echo "<tr> <th></th><td> <input type='submit' name = 'upisiOglasUbazuIzmena' value='Izmeni oglas'/> </td></tr>";

						echo "
						</table>
					</form>
					<div id='brisanjeOglasaIzBaze'>
						<form  method = 'post' name='formaZaBrisanjeOglasa'>
							<input type='submit' name='IzbrisiOglassss' value='Želim da izbrišem oglas'/>
						</form>
					</div>
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
							//echo "trenutno je ulogovan ".$_SESSION['username'];
		}	

		include 'upis_u_bazu_oglas.php';
		include 'update_oglasa_u_bazi.php';
		include 'brisanje_oglasa_iz_baze.php';
?>