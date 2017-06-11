<?php
   include('inc/db.inc'); 

   function proveri($korisnicko_ime, $sifra_korisnika) {

      global $veza;

      $hesiranaSifra = substr(md5("nenad".$sifra_korisnika."nenad"),0,20); //jer je u bazi podeseno da sifra bude 20 varchar
 
      //echo "$hesiranaSifra";
 
      $query = "SELECT * FROM korisnici WHERE
             idKorisnika='$korisnicko_ime' AND sifra='$hesiranaSifra'";
      $result = mysqli_query($veza, $query) or die(mysqli_error());
      $num = mysqli_num_rows($result);
      mysqli_close($veza);

      if($num > 0)
        return true;
      else
        return false;      
   }




    if (isset($_POST["login"]) == "true") {

      //proveravamo da li je korisnik vec ulogovan
      if (isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) { 
          echo "
           <script type='text/javascript'>
                 window.alert('Vec ste ulogovani.');
           </script>
            ";   
        } 
        else 
           if (isset($_POST["username"]) && isset($_POST["sifra"])) {
                if (!proveri($_POST["username"], $_POST["sifra"])){
              	echo "
                  <script type='text/javascript'>
                    window.alert('pogresno ime ili lozinka');
                  </script>
                  ";
                }    
        	     else 
                {
                 echo "
                  <script type='text/javascript'>
                    window.alert('Uspešno ste se ulogovali! Sada možete postaviti/izmeniti vaš oglas');
                  </script>
                  ";
                  $_SESSION['loggedin'] = true;
            		  $_SESSION["username"] = $_POST["username"];		
            		  //echo "<a href='index.php'>ok</a>";
            	 }
            }
      }


      
      if (isset($_POST["logout"]) == "true") {
          global $veza; //provera da li je korisnik uopste ulogovan da bi se izlogovao

          if (!isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == false) { 
            echo "
             <script type='text/javascript'>
                   window.alert('Vec ste se izlogovali.');
             </script>
              "; 
          }
          else
          {
          session_destroy();
          echo "
            <script type='text/javascript'>
                window.alert('Uspešno ste se izlogovali.');
            </script>
            ";
          }
        } 
  
?>