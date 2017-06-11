//funkcije koje realizuju slideshow u headeru

var slike=new Array("slike/slika1a.jpg","slike/slika2a.jpg","slike/slika3a.jpg");
var i=0;	

function menjajSlike()
{
	var id;

	id=window.setInterval("prikazi()", 3000);
}

function prikazi()
{
	i=(i+1)%slike.length;
	$('#slika').fadeOut(600,function() {
		$('#slika').attr("src",slike[i]);
		});
	$('#slika').fadeIn(500);
	
}	

function anim1()
{
	$('#navi1').fadeOut(20,function(){
		$('#navi1').css('background-color','#B8B8B8');
		$('#navi1').css('color','#383838');		
		});
		
		$('#navi1').fadeIn(50,function(){
		$('#navi1').css('background-color','#383838');
		$('#navi1').css('color','white');
		});
}

function anim2()
{
	$('#navi2').fadeOut(20,function(){
		$('#navi2').css('background-color','#B8B8B8');
		$('#navi2').css('color','#383838');		
		});
		
		$('#navi2').fadeIn(50,function(){
		$('#navi2').css('background-color','#383838');
		$('#navi2').css('color','white');
		});
}
function anim3()
{
	$('#navi3').fadeOut(20,function(){
		$('#navi3').css('background-color','#B8B8B8');
		$('#navi3').css('color','#383838');		
		});
		
		$('#navi3').fadeIn(50,function(){
		$('#navi3').css('background-color','#383838');
		$('#navi3').css('color','white');
		});
}
function anim4()
{
	$('#navi4').fadeOut(20,function(){
		$('#navi4').css('background-color','#B8B8B8');
		$('#navi4').css('color','#383838');		
		});
		
		$('#navi4').fadeIn(50,function(){
		$('#navi4').css('background-color','#383838');
		$('#navi4').css('color','white');
		});
}
function anim5()
{
	$('#navi5').fadeOut(20,function(){
		$('#navi5').css('background-color','#B8B8B8');
		$('#navi5').css('color','#383838');		
		});
		
		$('#navi5').fadeIn(50,function(){
		$('#navi5').css('background-color','#383838');
		$('#navi5').css('color','white');
		});
}



function ukloniInicijalniTekst1()
{
	if(document.getElementsByName('cenaOd')[0].value == "od")
		document.getElementsByName('cenaOd')[0].value = "";
}

function postaviInicijalniTekst1()
{
	if(document.getElementsByName('cenaOd')[0].value == "")
		document.getElementsByName('cenaOd')[0].value = "od";			
}

function ukloniInicijalniTekst2()
{
	if(document.getElementsByName('cenaDo')[0].value == "do")
		document.getElementsByName('cenaDo')[0].value = "";
}

function postaviInicijalniTekst2()
{	
	if(document.getElementsByName('cenaDo')[0].value == "")
		document.getElementsByName('cenaDo')[0].value = "do";	
		
}


function ukloniInicijalniTekst3()
{	
	if(document.getElementsByName('username')[0].value == "ovde unesite username")
		document.getElementsByName('username')[0].value = "";	
}


function postaviInicijalniTekst3()
{	
	if(document.getElementsByName('username')[0].value == "")
		document.getElementsByName('username')[0].value = "ovde unesite username";	
}

//AJAX #################################################################################################################################

function ajaxFunction()
{
	var xmlHttp; //xmlHttp čuva XMLHttpRequest() i ActiveXObject() metode
	try
	{
		// Firefox, Opera 8.0+, Safari
		xmlHttp=new XMLHttpRequest();//asinroni HTTP zahtev se kreira pomoću objekta XMLHTTPRequest 
									//Internet Explorer koristi ActiveXObject
	}
	catch (e)
	{
	// Internet Explorer
		try
		{
			xmlHttp=new ActiveXObject("Msxml2.XMLHTTP");
		} catch (e)
			{
			try
				{
					xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
				} catch (e)
					{
						alert("Vas browser ne podrzava AJAX!");
						return false;
					}
			}
	}
	xmlHttp.onreadystatechange=function() //readyState svojstvo čuva status odgovora servera (stanja 0 1 2 3 4-zahtev kompletiran)
	{
		if(xmlHttp.readyState==4)
		{
			document.mojaForma.vreme.value=xmlHttp.responseText; //u responseText se cuva odgovor servera 
		}
	}
	
	xmlHttp.open("GET","ajaxVreme.php",true);
	xmlHttp.send(null);
	//Da bi se poslao zahtev serveru, koriste se dve metode: open() i send()
	//Open() metoda uzima tri argumenta-prvi argument definiše način slanja zahteva serveru (GET ili POST)
									//	-drugi argument definiše URL skripte serverske strane
									// 	-dok treći argument ukazuje na to da bi zahtevom trebalo upravljati asinhronim prenosom podataka
	//Send() metoda sprovodi sam proces slanja zahteva serveru i ona najčešće prima argument null
}

function ajaxPozivi()
{
	var id;

	id = window.setInterval("ajaxFunction()", 1000);
}


//KOLACICI ####################################################################################################################################

function setCookie(cname,cvalue,exdays) { //funkcija za kreiranje kolacica parametri ime kolacica, vrednost kolacica i broj dana do isteka kolacica
    var d = new Date();	
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    var expires = "expires=" + d.toUTCString();
    document.cookie = cname+"="+cvalue+"; "+expires; //cuva se kao string
}

function getCookie(cname) { //ocitavanje kolacica
    var name = cname + "=";
    var ca = document.cookie.split(';'); //od stringa napravimo niz delimiter je ;
    for(var i=0; i<ca.length; i++) { // prolazimo kroz ceo niz i prolalazimo username i vrednost
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) != -1) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function checkCookie () {	//provera da li je postavljen kolacic
    var boja=getCookie("bojaPozadine");

    
    if (boja != "") {
	    	//alert('postavili ste boju'+boja);
        document.getElementById("omotac").style.backgroundColor=boja;
    } else {
       boja = prompt("Ukoliko želite možete postaviti boju pozadine po vašoj želji:","");
 
       if (boja != "" && boja != null) {
           setCookie("bojaPozadine", boja, 5);
       }
       else{
       		setCookie("bojaPozadine", "#B0B0B0", 5);
       }
    }
}

function checkCookie1() {	//ova funkcija u odnosu na prethodnu samo ima poziv funkcije clearCookie i poziva se klikom na div korisnicka podesavanja 
							//kako bi u bilo kom momentu korisnik mogao da ih promeni

	clearCookie();
    
    var boja=getCookie("bojaPozadine");

    
    if (boja != "") {
	    	//alert('postavili ste boju'+boja);
        document.getElementById("omotac").style.backgroundColor=boja;
    } else {
       boja = prompt("Ukoliko želite možete postaviti boju pozadine po vašoj želji(red,silver...):","");
 
       if (boja != "" && boja != null) {
           setCookie("bojaPozadine", boja, 5);
       }
       else{
       		setCookie("bojaPozadine", "#B0B0B0", 5);
       }
    }
}

function clearCookie(){
	boja = "";
    setCookie("bojaPozadine", boja, 5);
}

