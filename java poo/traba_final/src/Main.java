import File.ArquivosCvs;
import File.funcoes;
import Janelas.JanelaInicial;
import Json.Conversor;
import Json.Json;

public class Main {
    public static void main(String[] args) {
//        Json a =  Conversor.getJson("{\"mensagens\":[]}");
//        System.out.println(a.getArray_js("mensagens").getKeys());
//        JanelaInicial b = new JanelaInicial();
//        (new ArquivosCvs()).init(funcoes.cortar,"pasta_lx/a2.txt","pasta_lx/arquivopaciente_endereco_uf.sql","a3.txt");
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/pais2.txt","pasta_lx/arquivopaciente_endereco_nmpais.sql","a6.txt");
//        //(new ArquivosCvs()).init(funcoes.cortar,"pasta_lx/a6.txt","pasta_lx/arquivopaciente_endereco_uf.sql","a1.txt");
//
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/a6.txt","pasta_lx/arquivopaciente_endereco_uf.sql","a4.txt");
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/a4.txt","pasta_lx/a6.txt","a7.txt");
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/a7.txt","pasta_lx/arquivo_paciente_endereco_uf.txt","a5.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivo_paciente_endereco_uf.txt","pasta_lx/a5.txt","a8.txt");
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/a8.txt","pasta_lx/a5.txt","a9.txt");

//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivoestabelecimento_municipio_nome.sql","pasta_lx/arquivoestabelecimento_uf.sql","a10.txt");
//        (new ArquivosCvs()).init(funcoes.distinctKV,"pasta_lx/arquivoestabelecimento_municipio_codigo.sql","pasta_lx/a10.txt","a11.txt");
//        (new ArquivosCvs()).init(funcoes.cortar,"pasta_lx/a11.txt","pasta_lx/a10.txt","");
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/a2.txt","pasta_lx/arquivo_estabelecimento_uf.txt","a12.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivo_estabelecimento_municipio_nome.txt","pasta_lx/a12.txt","a13.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivo_estabelecimento_municipio_codigo.txt","pasta_lx/a13.txt","a14.txt");
//        vacina_nome -> vacina_tipo
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/fabricante.txt","pasta_lx/arquivovacina_fabricante_nome.sql","v1.txt"); // fab
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/tipo.txt","pasta_lx/arquivovacina_nome.sql","v2.txt"); // tipo
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/lote.txt","pasta_lx/arquivovacina_lote.sql","v3.txt"); // lote
//
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivovacina_categoria_codigo.sql","pasta_lx/v1.txt","v4.txt"); // cag - fab
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/v2.txt","pasta_lx/v4.txt","v5.txt"); // cag fab - tipo
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/v3.txt","pasta_lx/v5.txt","v6.txt"); // cag fab - tipo - lote
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/v6.txt","pasta_lx/a.txt","v7.txt");
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/v7.txt","pasta_lx/a.txt","v8.txt");
//
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/municipio.txt","pasta_lx/a.txt","municipio2.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivoestabelecimento_razaosocial.sql","pasta_lx/arquivoestalecimento_nofantasia.sql","e2.txt"); // social - nome
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivoestabelecimento_municipio_codigo.sql","pasta_lx/e2.txt","e3.txt"); // social - nome - municipio
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/e3.txt","pasta_lx/a.txt","e4.txt");
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/e4.txt","pasta_lx/a.txt","e5.txt");

//        (new ArquivosCvs()).init(funcoes.sql,"pasta_lx/arquivopaciente_id.sql","pasta_lx/p2.txt","p.txt");
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/arquivopaciente_id.sql","pasta_lx/a.txt","p1.txt");
////        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/p8.txt","pasta_lx/arquivopaciente_id.sql","p1.txt"); // doc_id - pac_id
//        (new ArquivosCvs()).init(funcoes.cortar,"pasta_lx/p1.txt","pasta_lx/arquivopaciente_datanascimento.sql","p10.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivopaciente_id.sql","pasta_lx/arquivopaciente_datanascimento.sql","p2.txt"); // doc_id - pac_id - dt
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/p2.txt","pasta_lx/arquivopaciente_racacor_codigo.sql","p3.txt"); // doc_id - pac_id - dt - raça
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/p3.txt","pasta_lx/arquivopaciente_endereco_coibgemunicipio.sql","p4.txt"); // doc_id - pac_id - dt - raça - municipio
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/sexo.txt","pasta_lx/arquivopaciente_enumsexobiologico.sql","p6.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/p4.txt","pasta_lx/p6.txt","p5.txt");
//        (new ArquivosCvs()).init(funcoes.distinctKV,"pasta_lx/arquivo_id.txt","pasta_lx/p5.txt","p7.txt");// doc_id - pac_id - dt - raça - municipio - sexo
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/p5.txt","pasta_lx/a.txt","p7.txt"); // doc_id - pac_id - dt - raça - municipio - sexo
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/p7.txt","pasta_lx/a.txt","p8.txt"); // doc_id - pac_id - dt - raça - municipio - sexo

        // arquivopaciente_racacor_codigo.sql
        // arquivopaciente_endereco_coibgemunicipio.sql
        // arquivopaciente_enumsexobiologico.sql

        // arquivovacina_descricao_dose.sql
//        (new ArquivosCvs()).init(funcoes.substituiKeyVl,"pasta_lx/dose.txt","pasta_lx/arquivovacina_descricao_dose.sql","apli_1.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivovacina_dataaplicacao.sql","pasta_lx/apli_1.txt","apli_2.txt");
//        (new ArquivosCvs()).init(funcoes.distinct,"pasta_lx/apli_2.txt","pasta_lx/apli_1.txt","apli_3.txt");
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/apli_2.txt","pasta_lx/apli_1.txt","apli_5.txt");
//        (new ArquivosCvs()).init(funcoes.key,"pasta_lx/e3.txt","pasta_lx/a.txt","e6.txt");
//        (new ArquivosCvs()).init(funcoes.cortar,"pasta_lx/e6.txt","pasta_lx/a.txt","e6.txt");
//
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/arquivo_pacientes_id.txt","pasta_lx/arquivo_vacina_id.txt","has.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/has.txt","pasta_lx/arquivo_aplicacao_id.txt","has_1.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/has_1.txt","pasta_lx/arquivovacina_grupoatendimento_codigo.sql","has_2.txt");
//        (new ArquivosCvs()).init(funcoes.uniom,"pasta_lx/has_2.txt","pasta_lx/arquivo_id.txt","has_3.csv");

        (new ArquivosCvs()).init(funcoes.sql,"sql/has_3.csv","pasta_lx/arquivo_vacina_id.txt","has.txt","paciente_has_vacina");

        // paciente id --
        // vacina_id --
        // aplicacao_id --
        // atendimento_id --
        // estabelecimento_id

    }
}
