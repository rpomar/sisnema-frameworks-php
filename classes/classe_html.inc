<?php
/**
 * Classe para gerenciamento de HTML
 *
 */
class html {
    protected $_tags = Array();
    protected $_otimizado = true;

    public function addTag(tag $_tag) {
        $this->_tags[] = $_tag;
        return sizeof($this->_tags)-1;
    }

    public function setOtimizado($_ot) {
        $this->_otimizado = (bool) $_ot;
    }

    public function deleteTag($_id) {
        unset($this->_tags[$_id]);
    }

    public function toHTML() {
        $_html = "";
        foreach($this->_tags as $_tag) {
            $_html .= $_tag->toHTML($this->_otimizado);
        }
        return $_html;
    }

}

/**
 * Define os tipos de TAG HTML disponiveis
 *
 */
class tipotag {
	protected $_nome;
	protected $_finaliza = true;

	public function __construct() {

	}

	public function getNome() {

	}

	public function getFinaliza() {

	}

}



/**
 * Define um Atributo para o marcador html relacionado
 *
 */
class atributo {
    protected $_nome;
    protected $_valor;

    public function __construct() {

    }

    public function getAtributo() {

    }

    public function getNome() {

    }

    public function getValor() {

    }
}


class tipospadrao {
    private $_tipos = Array();

    public function __construct() {
        $this->inicializa();
    }

    public function inicializa() {
        $this->_tipos = Array(  "HTML"=>new tipotag("HTML"),
            "HEAD"=>new tipotag("HEAD"),
            "TITLE"=>new tipotag("TITLE"),
            "LINK"=>new tipotag("LINK",false),
            "BODY"=>new tipotag("BODY"),
            "TABLE"=>new tipotag("TABLE"),
            "TBODY"=>new tipotag("TBOY"),
            "TR"=>new tipotag("TR"),
            "TH"=>new tipotag("TH"),
            "TD"=>new tipotag("TD"),
            "A"=>new tipotag("A"),
            "BR"=>new tipotag("BR",false),
            "FORM"=>new tipotag("FORM"),
            "INPUT"=>new tipotag("INPUT",false),
            "SELECT"=> new tipotag("SELECT"),
            "OPTION"=>new tipotag("OPTION"),
            "TEXTAREA"=>new tipotag("TEXTAREA"),
            "IMG"=>new tipotag("IMG"),
            "DIV"=>new tipotag("DIV"),
            "SPAN"=>new tipotag("SPAN"),
            "BUTTON"=>new tipotag("BUTTON"),
            "SCRIPT"=>new tipotag("SCRIPT"),
            "META"=>new tipotag("META",false),
            "COMMENT"=>new tipotag("COMMENT",false),
            "HR"=>new tipotag("HR",false),
            "P"=>new tipotag("P"),
            "MAP"=>new tipotag("MAP"),
            "IFRAME"=>new tipotag("IFRAME"),
            "AREA"=>new tipotag("AREA",false),
            "BASE"=>new tipotag("BASE",false),
            "STYLE"=>new tipotag("STYLE")
            );
}

public function getTipo($_tipo) {
}
}



/**
 * Classe que contém tags HTML
 *
 */
class tag {
    protected $_tipo;
    protected $_atributos = Array();
    protected $_valor;
    protected $_subtags = Array();

    public function __construct(tipotag $_tipo,$_atributos=Array(),$_valor=null) {
        $this->_tipo = $_tipo;
        $this->_atributos = (is_array($_atributos) ?  $_atributos : Array());
        $this->_valor = $_valor;
        return $this;
    }

    public function setValor() {

    }

    public function append() {

    }

    public function addAtributo() {
    }

    public function deleteAtributo() {

    }

    public function clearAtributos() {

    }

    public function addSubTag() {

    }

    public function deleteSubTag() {

    }

    public function clearSubTags() {

    }

    public function toHTML() {

    }

    public function getTipo() {

    }

    public function getAtributos() {

    }

    public function getLastSubTag() {

    }

}


/**
 * Classe geradora de uma lista de Eventos
 */
class Eventos {
    protected $_eventos = Array();

    public function addEvento($_tipo="ONCLICK",$_evento="") {
    }

    public function deleteEvento($_tipo) {
    }

    public function clearEventos() {
    }

    public function getEventos() {
    }

    public function setOnclick($_evento) {
    }

    public function setOnChange($_evento) {
    }

    public function setOnFocus($_evento) {
    }

    public function setOnBlur($_evento) {
    }

    public function setOnMouseOver($_evento) {
    }

    public function setOnMouseOut($_evento) {
    }

    public function setOnKeyPress($_evento) {
    }

}





?>
