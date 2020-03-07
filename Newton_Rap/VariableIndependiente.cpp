#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class VariableIndependiente{
    private:
    //Atributos
    string variable {};
    int exponente {};

    public:
    //Constructores
    VariableIndependiente(string valorVariable, int valorExponente){
        variable = valorVariable;
        exponente = valorExponente;
    }

    //Métodos
    int getExponente(){
        return exponente;
    }

    void setExponente(int exponenteNuevo){
        exponente = exponenteNuevo;
    }

    string getVariable(){
        return variable;
    }

    void setVariable(string variableNueva){
        variable = variableNueva;
    }

    double evaluar(double valor){
        if(exponente == 0)
            return 1;
        return pow(valor,exponente);
    }

    string cadena(){  
        if(exponente == 0) 
            return ""; 
        else if(exponente == 1)
            return variable;
        else
            return variable + "^" + to_string(exponente);
    }

};

class Monomio{
    private:
    double literal {};
    vector<VariableIndependiente> variables;

    public:
    Monomio(double valorLiteral, vector<string> valorVariables, vector<int> valorExponentes){
        int length {};

        length = valorExponentes.size();
        for(int i = 0; i < length; i++){
            VariableIndependiente aux {valorVariables[i],valorExponentes[i]};

            variables.push_back(aux);
        }

        literal = valorLiteral;
    }

    int getLiteral(){
        return literal;
    }

    void setLiteral(int literalNuevo){
        literal = literalNuevo;
    }

    double evaluar(vector<double> valores){
        double resultado {1};
        int length {};
        
        length = variables.size();
        for(int i = 0;i < length;i++){
            if(variables[i].getVariable() != "")
                resultado *= variables[i].evaluar(valores[i]);
        }
        
        resultado *= literal;
        return resultado;
    }

    string derivar(string var){
        int aux {};
        int contador {};
        
        for(int i = 0; i < (int) variables.size();i++){
            if(variables[i].getVariable() == var && variables[i].getExponente() == 0)
                return "";
            if(variables[i].getVariable() == var)
                aux = i;
            if(variables[i].getExponente() != 0)
                contador++;
        }

        string cadena {};
        double literalDerivada {variables[aux].getExponente() * literal};
        VariableIndependiente derivada {var,variables[aux].getExponente() - 1}
        
        if(contador > 1){
            if(literalDerivada == 1)
            if(literalDerivada == -1)

        }
        if(literalDerivada < 0)
            cadena += to_string((int) literalDerivada);
        else 
                cadena += "+" + to_string((int) literalDerivada);
        
        for(int i = 0; i < (int) variables.size();i++){
            if(variables[i].getVariable() == var)
                cadena += derivada.cadena();
            else 
                cadena += variables[i].cadena();
        }

        return cadena;
    }

    string cadena (){
        string cadena {""};

        if(literal == -1)
            cadena += "-";
        else if(literal == 1)
            cadena += "+";
        else if(literal < 0)
            cadena += to_string((int) literal);
        else if(literal > 0)
            cadena += "+" + to_string((int) literal);
        
        for(int i = 0;i < (int) variables.size();i++)
            cadena += variables[i].cadena();
        
        return cadena;
    }
};

class Funcion {
    private:
    vector<Monomio> terminos {};
    double constante {};

    public:
    Funcion (string funcion,int n) {
        int i {};
        int j {};
        vector<string> terminosAux {};

        for(i = 0;i < (int) funcion.size();i++){
            int contador {1};

            for(j = i;j < (int) funcion.size();j++){
                if(funcion[j] == ' ')
                    break;
                contador++;
            }
            terminosAux.push_back(funcion.substr(i,contador-1));
            i += contador-1;
        }
    
        for(i = 0;i < (int) terminosAux.size();i++){
            double valorLiteral {};
            vector<string> valorVariables {};
            vector<int> valorExponentes {};

            for(j = 0; j < (int) terminosAux[i].size();j++){
                if(j == 0){
                    if(isdigit(terminosAux[i][j+1])){
                        int contador {2};
                        int k {};

                        for(k = j + 2;k < (int) terminosAux[i].size();k++){
                            if(!isdigit(terminosAux[i][k]))
                                break;
                            contador++;
                        }

                        if(k == (int) terminosAux[i].size())
                            constante = stod(terminosAux[i].substr(j,contador));
                        else 
                            valorLiteral = stod(terminosAux[i].substr(j,contador));
                        
                        j += contador - 1;
                    }
                    else{
                        if(terminosAux[i][j] == '+')
                            valorLiteral = 1;
                        else 
                            valorLiteral = -1;
                    }
                }
                else{
                    if(valorVariables.empty() && !(terminosAux[i][j] == 'x')){
                        valorVariables.push_back("x");
                        valorExponentes.push_back(0);
                    }
                    
                    valorVariables.push_back(terminosAux[i].substr(j,1));

                    if(terminosAux[i][j+1] == '^'){
                        int contador {1};

                        for(int k = j + 3;k < (int) terminosAux[i].size();k++){
                            if(!isdigit(terminosAux[i][k]))
                                break;
                            contador++;
                        }

                        valorExponentes.push_back(stoi(terminosAux[i].substr(j + 2,contador)));
                        j += contador + 1;

                        if(!(terminosAux[i][j] == 'y') && n > 1){
                            valorVariables.push_back("y");
                            valorExponentes.push_back(0);
                        }
                    }
                    else 
                        valorExponentes.push_back(1);
                }
            }

            if(constante == 0){
                if(n > 2 && (int) valorVariables.size() < 3) {
                    valorVariables.push_back("z");
                    valorExponentes.push_back(0);
                }
                Monomio termino {valorLiteral,valorVariables,valorExponentes};
                terminos.push_back(termino);
            }
        }
    }

   double evaluar(vector<double> valoresVariables){
        double resultado {};
        int length {};
        
        length = terminos.size();
        for(int i = 0;i < length;i++){
            resultado += terminos[i].evaluar(valoresVariables);
        }
        
        resultado += constante;
        return resultado;
    }

    string cadena (){
        string cadena {""};
        
        for(int i = 0;i < (int) terminos.size();i++){
            if(i == ((int) terminos.size()) - 1)
                cadena += terminos[i].cadena();
            else
                cadena += terminos[i].cadena() + " ";
        }

        if(constante == 0.0)
            cadena += "";
        else if(constante < 0.0)
            cadena += " " + to_string((int) constante);
        else if(constante > 0.0)
            cadena += " +" + to_string((int) constante);

        return cadena;
    }

    string derivar (string var){
        string cadena {""};
    
        for(int i = 0;i < (int) terminos.size();i++)
            cadena += terminos[i].derivar(var) + " ";
        
        
        return cadena;
    }
};

void nombres () {
    cout <<"Navarro Ramos Karen"<<endl;
    cout <<"Gómez González Astrid"<<endl;
    cout <<"Márquez Rosas Lemuel Helon"<<endl;
}

int menu() {
    int respuesta {};
    cout <<"\t\t.:Menu:."<<endl;
    cout <<"1) Conjunto Uno"<<endl;
    cout <<"2) Conjunto Dos"<<endl;
    cout <<"3) Conjunto Tres"<<endl;
    cout <<"4) Conjunto Cuatro"<<endl;
    cout <<"5) Salir"<<endl;


    cout <<endl <<"Escoje una opcion: ";
    cin >> respuesta;

    return respuesta;
}

void uno () {
    string funcion1 {"+x^2 +xy -10"};
    string funcion2 {"+3xy^2 +y -50"};
    Funcion fx1 {funcion1,2};
    Funcion fx2 {funcion2,2};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << " " << fx1.derivar("x") << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << " " << fx2.derivar("x") << endl;


}

void dos () {
    // Funcion funcion1 {"+x^2 +y^2 -9",2};
    // Funcion funcion2 {"+x^2 +xy -10",2};
}

void tres () {
    string funcion1 {"+2x^2 -4x +y^2 +3z^2 +6z +2"};
    string funcion2 {"+x^2 +y^2 -2y +2z^2 -5"};
    string funcion3 {"+3x^2 -12x +y^2 -3z^2 +8"};
    Funcion fx1 {funcion1,3};
    Funcion fx2 {funcion2,3};
    Funcion fx3 {funcion3,3};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << endl;
    cout << fx3.cadena() << " " << (fx3.cadena() == funcion3) << endl;

}

void cuatro () {
    string funcion1 {"+x^2 -4x +y^2"};
    string funcion2 {"+x^2 -x -12y +1"};
    string funcion3 {"+3x^2 -12x +y^2 -3z^2 +8"};
    Funcion fx1 {funcion1,3};
    Funcion fx2 {funcion2,3};
    Funcion fx3 {funcion3,3};

    cout << fx1.cadena() << " " << (fx1.cadena() == funcion1) << endl;
    cout << fx2.cadena() << " " << (fx2.cadena() == funcion2) << endl;
    cout << fx3.cadena() << " " << (fx3.cadena() == funcion3) << endl;
}



int main() {
    int r {};
    // string funcion {"x^2+xy-10"};
    // int n {2};
    // Funcion a {funcion, n};
    // cout << boolalpha;
    // cout << (funcion == a.cadena()) << " " << a.cadena() << endl << a.derivar("x")<< endl;
cout<<boolalpha;
    nombres();
    do{
        r = menu();
        switch(r){
            case 1: uno();
                break;
            case 2: dos();
                break;
            case 3: tres();
                break;
            case 4: cuatro();
                break;
        }
    }while (r != 5);

    
    return 0;
}

