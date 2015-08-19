<?php


require_once('classes/classe_bancodados.inc');



$bd = new mysql('localhost','root');



$articles = $bd->executaSQL( "select * from cake.articles");

$line = '';

while($obj = $articles->fetch_object()){
	$line.=$obj->id;
	$line.=$obj->title;
	$line.=$obj->body;
	$line.="<br>";
}

echo $line;



?>

