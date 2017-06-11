<?php
	if(isset($_POST['pretrazi']) == true){

		//$marka = $_POST['proizvodjac'];

		$marka = $_POST['proizvodjac'];

		$karoserija = $_POST['karoserija'];

		$kubikaOd = intval($_POST['kubikaOd']);
		$kubikaDo = intval($_POST['kubikaDo']); 

		$godisteOd = intval($_POST['godisteOd']);
		$godisteDo = intval($_POST['godisteDo']);

		$cenaOd = intval($_POST['cenaOd']);
		$cenaDo = intval($_POST['cenaDo']);

		$region = $_POST['region'];

		if (isset($_POST['gorivo']))
			$gorivo = $_POST['gorivo'];
	
		if (isset($_POST['registrovan']))
			$reg = "da";
		if (isset($_POST['neregistrovan']))
			$reg = "ne";
		if (isset($_POST['registrovan']) && isset($_POST['neregistrovan']))
			$reg="svi";

		include('inc/db.inc'); //povezivanje sa bazom

		if($reg != "svi"){
			$sql = "SELECT * FROM `oglasi` WHERE oglasi.marka = '$marka' AND oglasi.karoserija = '$karoserija' AND oglasi.kubikaza>='$kubikaOd' AND kubikaza<='$kubikaDo'
					AND oglasi.godiste>='$godisteOd' AND oglasi.godiste<='$godisteDo' AND oglasi.cena>='$cenaOd' AND oglasi.cena<='$cenaDo' AND oglasi.region = '$region'
					AND oglasi.gorivo = '$gorivo' AND oglasi.registrovan = '$reg'";
		}
		else
		{
			$sql = "SELECT * FROM `oglasi` WHERE oglasi.marka = '$marka' AND oglasi.karoserija = '$karoserija' AND oglasi.kubikaza>='$kubikaOd' AND oglasi.kubikaza<='$kubikaDo'
					AND oglasi.godiste>='$godisteOd' AND oglasi.godiste<='$godisteDo' AND oglasi.cena>='$cenaOd' AND oglasi.cena<='$cenaDo' AND oglasi.region = '$region'
					AND oglasi.gorivo = '$gorivo'";
		}	

		$result = mysqli_query($veza, $sql) or die ("Doslo je do greske".mysqli_error($veza));

		$zaIspis = "";
		
		$brojRezultata = mysqli_num_rows($result);
		$visinaDivOdeljka = $brojRezultata * 90;
		?>


		<script type="text/javascript">
			var pom = parseInt("<?php echo $visinaDivOdeljka; ?>");

			if(visinaDivOdeljka < 450){
				document.getElementById("sadrzaj").style.height = "500px";	
			}
			else
				window.alert("treba");
		</script>

		<?php
		if(mysqli_num_rows($result)==0){
			echo "
			<script type='text/javascript'>
				window.alert('Ne postoji oglas sa koji ispunjava zadate kriterijume!');
			</script>";
		}
		else
		{			
			while($red=mysqli_fetch_assoc($result)){
				$idOglasaa = $red['idOglasa'];
				//echo "$idOglasa";
				$upit = "SELECT `telefon` FROM `kontakt` WHERE kontakt.idOglasa = '$idOglasaa'";

				$result1 = mysqli_query($veza, $upit) or die ("Doslo je do greske".mysqli_error($veza));
				$red1 = mysqli_fetch_assoc($result1);
				$telefonn = $red1['telefon']; 


				$upit2 = "SELECT `lokacija` FROM `lokacijeslika` WHERE lokacijeslika.idOglasa = '$idOglasaa'";//upit za citanje lokacije slike u bazi podataka

				$result2 = mysqli_query($veza, $upit2) or die ("Doslo je do greske (citanje lok.slike)".mysqli_error($veza));
				$red2 = mysqli_fetch_assoc($result2);
				$putanjaDoSlike = $red2['lokacija'];
				//echo "lokacija u bazi "."$putanjaDoSlike"; 

			$zaIspis = $zaIspis."<div class='oglasssi'><div id='oglasssiSlika'><img src=$putanjaDoSlike alt='nemoze se prikazati' height='84' width='130'></div><span>Marka: {$red['marka']}</span> <span>Karoserija: {$red['karoserija']}</span> <span>Kubikaza: {$red['kubikaza']}</span> <span>Godište: {$red['godiste']} </span> <span>Region: {$red['region']}</span> <span>Gorivo: {$red['gorivo']}</span> <span>Registrovan: {$red['registrovan']} </span><span>Cena: {$red['cena']} </span><span> Telefon: $telefonn  </div>";

				}
			?>



			<script type="text/javascript">
				var pomocna = "<?php echo $zaIspis; ?>";
				var element = document.getElementById("zadnjiOglasi");
				element.innerHTML = pomocna;
			</script>
			

		<?php
			
		}
		mysqli_close($veza);
	}
?>