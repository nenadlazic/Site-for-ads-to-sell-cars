<?php
	if(isset($_POST['upisiOglasUbazuIzmena']) == true){


		$marka = $_POST['proizvodjaccc'];
		$karoserija = $_POST['karoserijaaa'];
		$kubikaza = intval($_POST['kubikaaa']); 
		$godiste = intval($_POST['godisteee']);
		$cena = intval($_POST['cenaaa']);
		$region = $_POST['regionnn'];
		if (isset($_POST['gorivooo']))
			$gorivo = $_POST['gorivooo'];
		if (isset($_POST['registrovannn']))
			$regDa = "da";
		else 
			$regDa = "ne";
		if (isset($_POST['neregistrovannn']))
			$regNe = "da";
		else
			$regNe = "ne";
		if($regDa == "da")
			$reg = "da";
		else
			$reg = "ne";

		$textOglasa = $_POST['oglasTeksticc'];
		$telefon = trim($_POST['brTelefonaa']);

		$idKorisnika = $_SESSION['username'];
		$idOglasa = $idKorisnika."o1";


		//upis podataka u bazu
		include('inc/db.inc'); //povezivanje sa bazom

		$sql = "UPDATE oglasi SET idOglasa='$idOglasa',idKorisnika='$idKorisnika',karoserija='$karoserija',kubikaza='$kubikaza',
				godiste='$godiste',cena='$cena',region='$region',gorivo='$gorivo',registrovan='$reg',tekstOglasa='$textOglasa',
				marka='$marka' WHERE idOglasa = '$idOglasa' AND idKorisnika = '$idKorisnika'";



		
		$query = mysqli_query($veza, $sql) or die (mysqli_error($veza));

		//echo "<div id='proba'> Prosao prvi upit </div>";

		//promenicemo i br telefona u tabeli kontakt
		$sql = "UPDATE kontakt SET telefon= '$telefon' WHERE idOglasa = '$idOglasa'";


		$query1 = mysqli_query($veza, $sql) or die (mysqli_error($veza));

		//echo "<div id='proba'> Prosao drugi upit </div>";

		//treba i promena u tabeli za slike

		if (!file_exists($_FILES['imagee']['tmp_name']) || !is_uploaded_file($_FILES['imagee']['tmp_name'])) 
		{
		    //echo "<div id='proba'> Fotografija nije uploadvana </div>";
		    //Header('Refresh:3;url=3.php');
		}
		else
		{
			//echo "<div id='proba'> Uploadovana fotografija pokusaj </div>";
		    //Header('Refresh:3;url=3.php');
			$filename = time().mt_rand().$_FILES["imagee"]["name"];

			move_uploaded_file($_FILES["imagee"]["tmp_name"],"images/".$filename);
			
			$upit2 = "UPDATE lokacijeslika SET lokacija='images/".$filename."' WHERE idOglasa = '$idOglasa'";

			mysqli_query($veza,$upit2);

			//echo "<div id='proba'> Prosao treci upit </div>";
			echo "<div id='proba'> Uspešno ste izmenili oglas.</div>";
			Header('Refresh:2;url=3.php');
		}


		//echo "<div id='proba'> Provera3</div>";		


		mysqli_close($veza);
	}

?>