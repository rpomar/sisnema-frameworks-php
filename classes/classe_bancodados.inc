<?php
/**
 * Classe Básica para acesso a Banco de dados
 *	@abstract
 */
abstract class BancoDados {
	protected $_Tipo = null;	// Definido por cada banco de dados
	protected $_Servidor = 'localhost';
	protected $_Porta = 0;
	protected $_Usuario;
	protected $_Senha;
	protected $_Banco;
	protected $_conn = false;
	protected $_dataset = false;
	protected $_numrows = -1;
	protected $_tupla = false;
	protected $_posatual = -1;
	protected $_ultimoerro = "";
	protected $_ind_case = CASE_UPPER;

	abstract public function Conectar();
	abstract public function executaSQL($_sql);
	/*abstract protected function SetNumRows();
	abstract protected function navegainterno($_pos);
	abstract protected function proximointerno();
	abstract public function escapeString($_str);
	abstract public function getLimit($_arr);
	abstract protected function SetAffectedRows();*/

	public function GetServidor() {

		return $this->_Servidor;
	}

	public function GetUsuario() {
		return $this->_Usuario;
	}
	public function GetSenha() {
		return $this->_Senha;
	}

	public function GetBanco() {
		return $this->_Banco;
	}

	public function SetServidor($valor) {
		$this->_Servidor = $valor;
	}

	public function SetUsuario($valor) {
		$this->_Usuario = $valor;
	}

	public function SetSenha($valor) {
		$this->_Senha = $valor;
	}

	public function SetBanco($banco) {
		$this->_Banco = $banco;
	}


	

	public function GetConn(){
		if(! $this->_conn)
			{$this->SetConn();}
		return $this->_conn;
	}

	public function SetConn(){
		if( !$this->_conn){
			
			$this->_conn = new mysqli(
				$this->GetServidor(), 
				$this->GetUsuario(), 
				$this->GetSenha(),
				$this->GetBanco()
				);

		} else{
		
		return $this->_conn;

		}
	}

	public function SetPorta($_porta) {
	}

	public function startTransaction() {

		$this->executaSQL('START TRANSACTION');
	}

	public function commit() {

			$this->executaSQL('commit');

	}

	public function ROLLBACK() {

			$this->executaSQL('ROLLBACK');
	}

	protected function isSELECT($_sql,$_res) {
	}

	public function setCase($_case=CASE_UPPER) {
	}

	public function getNumRows() {
	}

	public function transforma() {
	}


	public function navega() {
	}

	public function primeiro() {
	}

	public function proximo() {
	}

	public function anterior() {
	}

	public function ultimo() {
	}

	public function getDadosAtual() {
	}

	public function getUltimoErro() {
	}

	public function converteDataToBD() {
	}

	public function converteDataHoraToBD() {
	}

	public function converteDataToHTML() {
	}

	public function converteDataHoraToHTML() {
	}
}

class mysql extends BancoDados{

	public function __construct($host = null, $usuario = null, $senha = null, $base = null){
		$this->SetServidor($host);
		$this->SetUsuario($usuario);
		$this->SetSenha($senha);
		$this->SetBanco($base);

	}

	public function insert($tabela, $campos, $valores){

		if (count($campos) != count ($valores)) {
			die ('<h1>nao permitido!</h1>');
		}

		$impcampos = implode(', ', $campos);
		
		function test_alter(&$item1){ $item1 = "'$item1'"; }

		array_walk($valores, 'test_alter');

		$impval = implode(', ', $valores);



		$sqlinsert= "INSERT INTO  $tabela($impcampos) VALUES ($impval)";

		$this->startTransaction();
		$statusInsert = $this->executaSQL($sqlinsert);
		$this->commit();

		return $statusInsert;



	}

	public function Conectar(){

		return $this->GetConn();

	}
	public function executaSQL($sql){

		return $this->GetConn()->query($sql);

	}
}