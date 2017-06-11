<?php  
	include('inc/db.inc');  //ukljucujemo kod za povezivanje sa bazom podataka (tu unosimo parametre za povezivanje)
			
			
	// registrovanje
	$ime = $_POST['imeKorisnika'];
	$ime = mysqli_real_escape_string($veza, $ime); //ova funkcija belezi specijalne karaktere u stringovima za cuvanje u sql naredbama

	$prezime = $_POST['prezimeKorisnika'];
	$prezime = mysqli_real_escape_string($veza, $prezime);

	$imeNaSajtu = $_POST['imeNaSajtu'];
	$imeNaSajtu = mysqli_real_escape_string($veza, $imeNaSajtu);

	$email = $_POST['emailKorisnika'];
	$email = mysqli_real_escape_string($veza, $email);

	$password = $_POST['sifrica'];
	$password = md5("nenad".$password."nenad"); //,,zasoljavamo" lozinke radi vece bezbednosti, preporuka da se ne cuvaju otvorene lozinke pa koristimo md5 i sh1 vec hesirane
	$password = mysqli_real_escape_string($veza, $password);	

	//radimo proveru da li vec postoji korisnik registrovan sa datom mail adresom	
	$result = mysqli_fetch_row(mysqli_query($veza, "SELECT COUNT(idKorisnika) FROM korisnici WHERE mail='$email'"));
	
	$emailGreska ="";

	if($result[0] > 0){
		$emailGreska = "Ovaj e-mail je vec registrovan na našem sajtu!<br />"; 
	}

	//radimo proveru da li vec postoji korisnik registrovan sa datim imenom na sajtu (koje ne mora biti pravo ime korisnika
	//idKorisnika ce nam zapravo biti ovo imeNaSajtu pod kojim se korisnik jedinstveno identifikuje

	$result = mysqli_fetch_row(mysqli_query($veza, "SELECT COUNT(idKorisnika) FROM korisnici WHERE idKorisnika='$imeNaSajtu'"));
	
	$imeNaSajtuGreska = "";

	if($result[0] > 0){
		$imeNaSajtuGreska = "imeNaSajtu koje ste zadali se vec koristi, pokusajte sa nekim drugim!<br />"; 
		
	}

	$sql = "INSERT INTO korisnici (idKorisnika, ime, prezime, sifra, mail)
			VALUES('$imeNaSajtu','$ime', '$prezime', '$password', '$email')";

	//echo "$sql";

	if(strlen($emailGreska)){
	echo "
		<script type='text/javascript'>
			window.alert('Vec postoji korisnik registrovan sa email-om koji ste uneli');
			history.back();
		</script>
	";
	}
	else
			if(strlen($imeNaSajtuGreska) != 0){
			echo "
				<script type='text/javascript'>
					window.alert('Vec postoji korisnik registrovan sa imeNaSajtu koji ste uneli');
					history.back();
				</script>
				";

			}
			else
			{
				$query = mysqli_query($veza, $sql) or die (mysqli_error($veza));
	
				mysqli_close($veza);
				header ('Location: potvrdaRegistrovanja.php?rsucc=Registration success!'); //sa ovim vrsimo redirekciju na zeljenu php stranu
				exit();//prekidamo tekuci skript
			}

?> 