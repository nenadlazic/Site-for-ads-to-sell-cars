<?php 
	function dravContact()
	{
		echo "
			<div id='kontakt'>
				<img src='slike/AudiA4.jpg' alt='slika se nemoze prikazati' width='998' height='698'/>
				<div id='kont1'>
					<p class='inl'> Kontakt redakcije sajta </p><br/>
					Administrator: Nenad Lazić <br/>
					e-mail: nenadlazic13@gmail.com <br/>
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							 mi12012@alas.matf.bg.ac.rs <br/>
					telefon: 060/406-19-33 <br/>

					<div id='odmahPosaljiMail'>
						<form action='' method='post' name='slanjePoruke' onsubmit='return proveriFormuPoruke();'>
							&nbsp; Pošaljite odmah poruku redakciji<br/>
							<textarea rows='2' cols='34' name='porukica' value='ovde unesite tekst poruke...'>";

					echo "</textarea><br/>
							&nbsp; e-mail adresa za odgovor <br/>
							<input type='email' name='mailkorisnika'>&nbsp;&nbsp;
							<input type='submit' name='submitZaSlanjePoruke' value='Pošalji'>	
						</form>";

			
				// if(isset($_POST['submitZaSlanjePoruke'])){
				// 	ini_set("SMTP","mail.example.com");
 


				// 	$from_mail = 'korisnik@gmail.com'; //email adresa posiljaoca
				// 	$reply_mail = $_POST['mailkorisnika']; //email adresa za odgovor mail servera
				// 	$to="nenadlazic13@gmail.com";
				// 	$subject="mail korisnika sajta autooglasi.rs";
					


				// 	$headers = 'MIME-Version: 1.0' . "\r\n"; //MIME v1.0 kompatibilan
				// 	$headers .= 'Content-type: text/plain; charset=utf-8' . "\r\n"; //tip i enkoding
				// 	$headers .= 'From: '.$from_mail."\r\n" .'Reply-To: '.$reply_mail. "\r\n" .'X-Mailer: PHP/'.phpversion(); //'From', 'Reply-To' i 'X-Mailer'
				// 	//generisanje poruke
				// 	$message = "Pozdrav sa autooglasi"; 
				// 	$mail = mail($to, $subject, $message, $headers);

				// 	//if(mail($to,$subject,$message))//TODO ovo pravi problem sa konekcijom na mail server
				// 	// if(mail($to,$subject,$message))
				// 	// 	echo "Poruka je poslata.";
				// 	// else
				// 	// 	echo "Ups.. Poruka nije poslata.. proverite podesavanja...";
				// }



				echo "	</div>
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