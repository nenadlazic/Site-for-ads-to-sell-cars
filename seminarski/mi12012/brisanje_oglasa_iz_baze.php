<?php
	if(isset($_POST['IzbrisiOglassss']) == true){
		include('inc/db.inc'); //povezivanje sa bazom

		$idKorisnika = $_SESSION['username'];
		$idOglasa = $idKorisnika."o1";
		
		$sql = "DELETE FROM oglasi WHERE idOglasa = '$idOglasa'";

		$result = mysqli_query($veza,$sql) or die (mysqli_error($veza));

		echo "<div id='proba'> Uspešno ste izbrisali oglas.</div>";
		Header('Refresh:3;url=3.php');

		mysqli_close($veza);
	}

?>
