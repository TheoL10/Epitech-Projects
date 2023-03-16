import 'dart:html';

import 'package:flutter/material.dart';
import '/components/my_button.dart';
import '/components/my_textfield.dart';
import '/components/square_tile.dart';
import 'dart:convert';
import 'dart:core';
import 'package:http/http.dart' as http;
import 'package:url_launcher/url_launcher.dart';
//import url launcher

class ApiService {
  static const String apiUrl = "http://127.0.0.1:8081";

  static String token = "";
  static String name = "";
  static double screenWidth = 0;
  static double screenHeight = 0;
  static Orientation orientation = Orientation.portrait;


  //Setter and getter for token under this comment
  static void setToken(String newToken) {
    token = newToken;
  }

  static String getToken() {
    return token;
  }

  static String getName() {
    return name;
  }

  static void setName(String newName) {
    name = newName;
  }

  static Future<Map<String, dynamic>> createService(Map<String, dynamic> service) async {
    final response = await http.post(Uri.parse(apiUrl + "/mobile/createService"),
      body: {
        "name": service["name"],
        "api": service["api"],
        "action": service["action"],
        "api2": service["api2"],
        "reaction": service["reaction"],
        "token": service["token"],
      }
    );

    if(response.statusCode == 200) {
      print(response.body);
      return jsonDecode(response.body);
    } else 
    {
      print("non");
      print(response.body);
      throw Exception('Failed to create service');
    }
  }

  static Future<Map<String, dynamic>> register(String name, String email, String phone, String password) async {
  final response = await http.post(
    Uri.parse(apiUrl + "/mobile/register"),
    body: {
      "name": name,
      "email": email,
      "phone": phone,
      "pass": password
    }
  );

  if(response.statusCode == 200) {
    print(response.body);
    return jsonDecode(response.body); 
  } else {
    throw Exception('Failed to register user');
  }
}

static Future<Map<String, dynamic>> login(String name, String password) async {
  print("in login");
  print(name);
  print(password);
  print(apiUrl + "/mobile/login");
  final response = await http.post(
    Uri.parse(apiUrl + "/mobile/login"),
    body: {
    "name": name,
    "pass": password
  });
  if (response.statusCode == 200) {
    ApiService.setName(name);
    return jsonDecode(response.body);
  } else {
    throw Exception('Failed to log in user');
  }
}

static Future<http.Response> getServices() async {
  final url = Uri.parse('http://127.0.0.1:8081/mobile/getServices');
  final response = await http.post(
    url,
    body: {
      'token': ApiService.getToken(),
    },
  );
  return response;
}

//delete service with token and id in parameter of post request
static Future<http.Response> deleteService(String id) async {
  final url = Uri.parse('http://127.0.0.1:8081/mobile/deleteService');

  final response = await http.delete(
    url,
    body: {
      'id': id,
      'token': ApiService.getToken(),
    },
    encoding: Encoding.getByName('utf-8'),
  );
  return response;
}

//get method for apiUrl + "/auth/discord"
static Future<http.Response> authDiscord() async {
  const url2 ="http://127.0.0.1:8081/auth/discord";
  if (await canLaunch(url2)) {
    await launch(url2 + "?token=" + await ApiService.getToken());
  } else {
    throw 'Could not launch $url2';
  };
  final url = Uri.parse('http://127.0.0.1:8081/auth/discord');
  final response = await http.get(
    url,
    headers: {
      'token': '${ApiService.getToken()}',
    },
  );
  print(response.body);
  return response;
}
}

String name = "";


double screenWidth = 0;

double screenHeight = 0;

Orientation orientation = Orientation.portrait;

void setName(String newName) {
    name = newName;
  }

  String getName() {
    return name;
  }

  double getScreenWidth() {
    return screenWidth;
  }

  double getScreenHeight() {
    return screenHeight;
  }

  Orientation getOrientation() {
    return orientation;
  }

class LoginPage extends StatelessWidget {
  LoginPage({super.key});

  // text editing controllers
  final usernameController = TextEditingController();
  final passwordController = TextEditingController();
  final screenHeight = getScreenHeight();
  final screenWidth = getScreenWidth();
  
  
  // sign user in method


  @override
  Widget build(BuildContext context) {
    
    return Scaffold(
      backgroundColor: Colors.grey[300],
      body: SafeArea(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // logo
              const Icon(
                Icons.lock,
                size: 100,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // welcome back, you've been missed!
              Text(
                'Welcome!',
                style: TextStyle(
                  color: Colors.grey[700],
                  fontSize: 16,
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 102.4,
            ),

              // username textfield
              MyTextField(
                controller: usernameController,
                hintText: 'Name',
                obscureText: false,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              // password textfield
              MyTextField(
                controller: passwordController,
                hintText: 'Password',
                obscureText: true,
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 256,
            ),

              // forgot password?
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: [
                    Text(
                      'Forgot Password?',
                      style: TextStyle(color: Colors.grey[600]),
                    ),
                  ],
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 102.4,
            ),

              // sign in button
              MyButton(
                onTap: () async {
                  print("login");
                  print(usernameController.text);
                  print(passwordController.text);
                  Map<String, dynamic> response = await ApiService.login(usernameController.text, passwordController.text);
                  print(response);
                  print("after button");
                  if(response["msg"] == "OK") {
                    ApiService.setToken(response["token"]);
                    print("token");
                    print(ApiService.getToken());
                    Navigator.pushNamed(context, '/home');
                  } else {
                    print("error");
                  }
                },
              ),
              
              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // or continue with
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25.0),
                child: Row(
                  children: [
                    Expanded(
                      child: Divider(
                        thickness: 0.5,
                        color: Colors.grey[400],
                      ),
                    ),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 10.0),
                      child: Text(
                        'Or continue with',
                        style: TextStyle(color: Colors.grey[700]),
                      ),
                    ),
                    Expanded(
                      child: Divider(
                        thickness: 0.5,
                        color: Colors.grey[400],
                      ),
                    ),
                  ],
                ),
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // google + apple sign in buttons
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: const [
                  // google button
                  SquareTile(imagePath: 'lib/images/google.png'),

                  SizedBox(width: 25),

                  // apple button
                  SquareTile(imagePath: 'lib/images/apple.png')
                ],
              ),

              SizedBox(
              height: MediaQuery.of(context).size.height / 51.2,
            ),

              // not a member? register now
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text(
                    'Not a member?',
                    style: TextStyle(color: Colors.grey[700]),
                  ),
                  const SizedBox(width: 4),
                  GestureDetector(
                    onTap: () {
                      Navigator.pushNamed(context, '/register');
                    },
                    child: Text(
                      'Register now',
                      style: TextStyle(
                        color: Colors.blue,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}

class CreateServiceScreen extends StatefulWidget {
  @override
  _CreateServiceScreenState createState() => _CreateServiceScreenState();
}

class _CreateServiceScreenState extends State<CreateServiceScreen> {

    
  String? _name;
  String? _selectedApi;
  String? _selectedApi2;
  String? _selectedAction;
  String? _selectedReaction;
  String? _token;
  List<dynamic> _subscribedServices = [];
  bool displayServices = false;
  
  final _formKey = GlobalKey<FormState>();

  @override

  void initState() {
    super.initState();
    _token = ApiService.getToken();
    ApiService.getServices().then((value) {
      setState(() {
        _subscribedServices = jsonDecode(value.body);
      });
    });
  }

  @override

  


  final List<String> apis = ["Discord", "Meteo"];
  final List<String> apis2 = ["Discord", "EMail"];
  final Map<String, List<String>> actions = {
    "Discord": ["On server join or left", "On profil update"],
    "Meteo": ["Chance of rain", "Too cold","Too hot"],
  };
  final Map<String, List<String>> reactions = {
    "Discord": ["Get notified on discord chat"],
    "EMail": ["Receive an email when action triggered"],
  };


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        //add a setting button in appbar

        leading: IconButton(
          icon: Icon(Icons.logout),
          onPressed: () {
            Navigator.pushNamed(context, '/login');
          },
        ),

        
        title: Text("Welcome ${ApiService.getName()}, here you can create a new service!"),
        backgroundColor: Colors.grey[500],
        actions: [
          IconButton(onPressed: () async {
    const url = 'http://134.122.68.99';
    if (await canLaunch(url)) {
      await launch(url);
    } else {
      throw 'Could not launch $url';
    }
  },
  icon: Icon(Icons.document_scanner),),
          IconButton(
            icon: Icon(Icons.settings),
            onPressed: () {
              Navigator.pushNamed(context, '/settings', arguments: _token);
            },
            ),
        ],
          ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              //name field
              TextFormField(
                decoration: InputDecoration(
                  labelText: "Service Name",
                  //text centered
                  labelStyle: TextStyle(
                    color: Colors.grey[700],
                    fontSize: 16,
                  ),

                  //the cursor in the text that indicate where you are typing should be black

                  focusedBorder: OutlineInputBorder(
                    borderSide: BorderSide(color: Colors.black),
                  ),
                  enabledBorder: OutlineInputBorder(
                    borderSide: BorderSide(color: Colors.grey),
                  ),
                
                ),
                validator: (String? value) {
                  if(value == null || value.isEmpty) {
                    return "Please enter a name";
                  }
                  return null;
                },
                onChanged: (String? value) {
                  setState(() {
                    _name = value;
                  });
                },
              ),
              DropdownButtonFormField<String>(
                value: _selectedApi,
                onChanged: (String? value) {
                  setState(() {
                    _selectedAction = null;
                  });
                  setState(() {
                    _selectedApi = null;
                  });
                  setState(() {
                    _selectedApi = value;
                  });
                },
                items: apis?.map((String value) {
                  return DropdownMenuItem<String>(
                    value: value,
                    child: Text(value),
                  );
                }).toList(),
                decoration: InputDecoration(
                  labelText: "API",
                ),
              ),
              DropdownButtonFormField<String>(
                value: _selectedAction,
                onChanged: (String? value) {
                  setState(() {
                    _selectedAction = value;
                  });
                },
                items: actions[_selectedApi ?? ""]?.map((String value) {
                  return DropdownMenuItem<String>(
                    value: value,
                    child: Text(value),
                  );
                }).toList() ?? [],
                decoration: InputDecoration(
                  labelText: "ACTION",
                ),
                ),
                DropdownButtonFormField<String>(
                value: _selectedApi2,
                onChanged: (String? value) {
                  setState(() {
                    _selectedReaction = null;
                  });
                  setState(() {
                    _selectedApi2 = null;
                  });
                  setState(() {
                    _selectedApi2 = value;
                  });
                },
                items: apis2?.map((String value) {
                  return DropdownMenuItem<String>(
                    value: value,
                    child: Text(value),
                  );
                }).toList(),
                decoration: InputDecoration(
                  labelText: "API",
                ),
                ),
                DropdownButtonFormField<String>(
                    value: _selectedReaction,
                    onChanged: (String? value) {
                        setState(() {
                        _selectedReaction = value;
                        });
                    },
                    items: reactions[_selectedApi2 ?? ""]?.map((String value) {
                        return DropdownMenuItem<String>(
                        value: value,
                        child: Text(value),
                        );
                    }).toList() ?? [],
                    decoration: InputDecoration(
                        labelText: "REACTION",
                    ),
                    ),
                    
                    SizedBox(
              height: MediaQuery.of(context).size.height / 160,
            ),
                    ElevatedButton(
                    onPressed: () async {
                        if (_formKey.currentState?.validate() ?? false) {
                        if (_selectedApi == "Discord") {
                          if (_selectedAction == "On server join or left") {
                            _selectedAction = '1';
                          } else
                            _selectedAction = '2';
                        }
                        else {
                          if (_selectedAction == "Chance of rain") {
                            _selectedAction = '1';
                          } else if (_selectedAction == "Too cold") {
                            _selectedAction = '2';
                          } else
                            _selectedAction = '3';
                        }
                        
                        final Map<String, dynamic> service = {
                            "name": _name,
                            "api": _selectedApi,
                            "action": _selectedAction,
                            "api2": _selectedApi2,
                            "reaction": '1',
                            "token": ApiService.getToken()
                        };

                        _formKey.currentState?.reset();
                        _selectedApi = null;
                         _selectedApi2 = null;
                         _selectedAction = null;
                        _selectedReaction = null;
                        _name = null;
                      
                        final response = await ApiService.createService(service);
                        //refresh get services every time a service is created
                        //get the services again


                        
                        }
                    },
                    style: ButtonStyle(
                        backgroundColor: MaterialStateProperty.all(Colors.black),
                    ),
                    child: Text("Create Service")






                    //refresh get services every time a service is created

                    //Display all the services created by the user using the ApiService.getServices() method -->

                    //get the services again


                    

                    
                    
                    ),
                    Expanded(
  child: Column(
    children: [

          Expanded(
            child: Column(
              children: [
                ElevatedButton(
                  onPressed: () {
                    setState(() {
                      displayServices = true; // Set the flag to true
                    });
                  },
                  style: ButtonStyle(
                    backgroundColor: MaterialStateProperty.all(Colors.black),
                  ),
                  child: Text('Display Services'),
                ),
                if (displayServices) // Conditionally display the FutureBuilder
                  Expanded(
                    child: FutureBuilder(
                      future: ApiService.getServices(),
                      builder: (BuildContext context, AsyncSnapshot snapshot) {
                        if (snapshot.hasData) {
                          final data = snapshot.data;
                          final services = jsonDecode(data.body);
                          return ListView.builder(
                            itemCount: services.length,
                            itemBuilder: (BuildContext context, int index) {
                            String msg1 = "";
                            String msg2 = "";
                            if (services[index]["action_service"] == "Discord") {
                              if (services[index]["action"] == "1") {
                                msg1 = "On server join or left";
                              } else {
                                msg1 = "On profile update";
                              }
                            }

                            if (services[index]["action_service"] == "Meteo") {
                              if (services[index]["action"] == "1") {
                                msg1 = "Chance of rain";
                              } else if (services[index]["action"] == "2") {
                                msg1 = "Too cold";
                              } else {
                                msg1 = "Too hot";
                              }
                            }

                            if (services[index]["reaction_service"] == "Discord")
                              msg2 = "Get notified on Discord chat";
                            else
                              msg2 = "Receive an email when action triggered";
                              return ListTile(
                                title: Text(services[index]["name"]),
                                subtitle: Text(services[index]["action_service"] + ", " + msg1 + ", " + msg2),
                                leading: Image.asset("lib/images/" + services[index]["action_service"].toLowerCase() + ".png"),
                                trailing: Icon(Icons.delete),
                                onTap: () async {
                                  final response = await ApiService.deleteService(services[index]["id"].toString());
                                  if (response.statusCode == 200) {
                                    setState(() {});
                                  }
                                },
                              );
                            },
                          );
                        } else {
                          return Center(child: CircularProgressIndicator());
                        }
                      },
                    ),
                  ),
              ],
            ),
          ),
          
    ],  
  ),
),










                      //Store the response from the ApiService.getServices() method in a variable called services and display it in a listv

                    

                    //Display all the services created by the user using the ApiService.getServices() method -->


                    //Display all the services created by the user using the ApiService.getServices() method -->
                    
                    
            ],
            ),
        ),
        ),
        // all the services available for the user should be displayed in a scrollable list from left to right      
        // the user should be able to click on a service and see the actions and reactions available for that service in a
    );
    }
}