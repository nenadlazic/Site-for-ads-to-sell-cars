<?php
	if(isset($_POST['upisiOglasUbazu']) == true){

		$marka = $_POST['proizvodjacc'];
		$karoserija = $_POST['karoserijaa'];
		$kubikaza = intval($_POST['kubikaa']); 
		$godiste = intval($_POST['godistee']);
		$cena = intval($_POST['cenaa']);
		$region = $_POST['regionn'];
		if (isset($_POST['gorivoo']))
			$gorivo = $_POST['gorivoo'];
		if (isset($_POST['registrovann']))
			$regDa = "da";
		else 
			$regDa = "ne";
		if (isset($_POST['neregistrovann']))
			$regNe = "da";
		else
			$regNe = "ne";
		if($regDa == "da")
			$reg = "da";
		else
			$reg = "ne";

		$textOglasa = $_POST['oglasTekstic'];
		$telefon = trim($_POST['brTelefona']);

		$idKorisnika = $_SESSION['username'];
		$idOglasa = $idKorisnika."o1";

		//echo "<div id='proba'>odabrali ste id $idOglasa  ;</div>";


		//upis podataka u bazu
		include('inc/db.inc'); //povezivanje sa bazom

		$sql = "INSERT INTO `oglasi`(`idOglasa`, `idKorisnika`, `karoserija`,
		 `kubikaza`, `godiste`, `cena`, `region`, `gorivo`, `registrovan`,
		  `tekstOglasa`, `marka`) VALUES ('$idOglasa','$idKorisnika','$karoserija',
		  '$kubikaza','$godiste','$cena','$region','$gorivo','$reg','$textOglasa','$marka')
		";

		$query = mysqli_query($veza, $sql) or die (mysqli_error($veza));

		//ocitacemo i email iz tabele korisnici kako bi upisali u podatke o oglasu

		$sql = "SELECT `mail` FROM `korisnici` WHERE korisnici.idKorisnika = '$idKorisnika'";	

		$resultMail = mysqli_query($veza, $sql) or die (mysqli_error($veza));
		$row = mysqli_fetch_array($resultMail);
		$mail = $row['mail'];

		$sql = "INSERT INTO `kontakt`(`idOglasa`, `mail`, `telefon`) VALUES ('$idOglasa','$mail','$telefon')";

		$query1 = mysqli_query($veza, $sql) or die (mysqli_error($veza));


		//treba i upis u tabelu za slike

		if (!file_exists($_FILES['image']['tmp_name']) || !is_uploaded_file($_FILES['image']['tmp_name'])) 
		{
		    //echo "<div id='proba'> Fotografija nije uploadvana </div>";
		    //Header('Refresh:3;url=3.php');
		}
		else
		{
			//echo "<div id='proba'> Uploadovana fotografija pokusaj </div>";
		    //Header('Refresh:3;url=3.php');
			$filename = time().mt_rand().$_FILES["image"]["name"];

			move_uploaded_file($_FILES["image"]["tmp_name"],"images/".$filename);
			
			$upit2 = "INSERT INTO `lokacijeslika`(`idOglasa`, `lokacija`) VALUES ('$idOglasa','images/".$filename."')";


			mysqli_query($veza,$upit2);
			//echo "Uspesno obavljeno ubacivanje";
			//Header('Refresh:3;url=../index.php');
			echo "<div id='proba'> Uspešno ste postavili oglas.</div>";
			Header('Refresh:3;url=3.php');
		}

		mysqli_close($veza);
	}

?>
