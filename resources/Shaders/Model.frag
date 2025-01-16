 varying vec2 v_TexCoord;                             
 varying vec3 v_Normal;                               
 varying vec3 v_FragPos;                              
                                                      
 uniform int u_EnableTexture;                         
 uniform int u_EnableLighting;                        
 uniform sampler2D u_Texture;                         
 uniform vec4 u_Diffuse;                              
 uniform vec4 u_Color;                                
 uniform vec3 u_ViewPos;                              
                                                    
 void main()                                          
 {                                                    
   vec4 tex = vec4(1, 1, 1, 1);                       
   if(u_EnableTexture == 1)                           
   {                                                  
     tex *= texture2D(u_Texture, v_TexCoord);         
   }                                                  
   tex *= u_Diffuse;                                  
   tex *= u_Color;                                    
   if(u_EnableLighting == 1)                          
   {                                                  
     vec3 lighting = vec3(0, 0, 0);                   
     vec3 lightpos = vec3(100, 100, 100);             
     vec3 lightdir = normalize(lightpos - v_FragPos); 
     vec3 normal = normalize(v_Normal);               
     float diff = max(dot(normal, lightdir), 0.0);    
     lighting += vec3(diff);                          
     vec3 viewdir = normalize(u_ViewPos - v_FragPos);
     vec3 reflectdir = reflect(-lightdir, normal);    
     float spec = pow(max(dot(viewdir, reflectdir),   
       0.0), 32.0);                                   
     lighting += vec3(spec);                          
     lighting = min(lighting, vec3(1, 1, 1));         
     lighting = max(lighting, vec3(0.2, 0.2, 0.2));   
     tex *= vec4(lighting, 1);                        
   }                                                  
   gl_FragColor = tex;                                
 }                                                    