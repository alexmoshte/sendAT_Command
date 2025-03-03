/*
 * certs.h
 *
 *  Created on: Dec 10, 2024
 *      Author: moshte
 */

#ifndef INC_CERTS_H_
#define INC_CERTS_H_

#define CA_CRT                                                           \
"-----BEGIN CERTIFICATE-----\n"                                      \
"MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n" \
"ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n" \
"b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n" \
"MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n" \
"b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n" \
"ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n" \
"9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n" \
"IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n" \
"VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n" \
"93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n" \
"jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n" \
"AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n" \
"A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n" \
"U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n" \
"N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n" \
"o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n" \
"5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n" \
"rqXRfboQnoZsG4q5WTP468SQvvG5\n"                                     \
"-----END CERTIFICATE-----\n"
#define SERVER_CERT \
"-----BEGIN CERTIFICATE-----\n"										\
"MIIDWTCCAkGgAwIBAgIUMBQJAZRteavQWtpsXr1U0zCrs5swDQYJKoZIhvcNAQEL\n"\
"BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n"\
"SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI0MDQwODEyMDcz\n"\
"M1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n"\
"ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAJ+GK3nf8TKDuDQ/EzmJ\n"\
"eJI1pRDu6n85/fkBAAgpRp3DkKGuJbc+HM3BJJLtxbRJlsqkx4BNK1JijaeLiBmR\n"\
"qlduGQrQKjUuq4WBoE6I8YFdz+4o5QBkJKf61CgLlqV6NvcAQr4cv+T6mAXsbbmc\n"\
"aEqX8YZky+Chr4rWepzSe9sJtNc4qzPaTTkOMhYfnWSQFFJPPL8VlWjnNJOgo78P\n"\
"eERGnj0QO4eY7bhbtgYUH9QY9OJ2d/NQe8QwKXSqX9xQ6mQjwrVBIwsRbGJzDvy0\n"\
"TjrINP5/b5bs9EybrSZzr55pRgixVC7NbbjyFQzxBwoXqWMEy9q0zmE1+7ZNFTBL\n"\
"xQMCAwEAAaNgMF4wHwYDVR0jBBgwFoAUrP0kQb4WtrESq7zQzhPbdMkniwgwHQYD\n"\
"VR0OBBYEFMYZC2JbuLXGJvtFx+LXGlxL6OuRMAwGA1UdEwEB/wQCMAAwDgYDVR0P\n"\
"AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBjoFYRKwuVavCIu1AWwreM+ahn\n"\
"lbbSAZTQGF52vZXqHB9EQi6+ZPC/QjeBzctzziC0qgD+Ew0sOJ4hGST7egvjGGXP\n"\
"1VADSxETk4jLozEKkWUMO2gJEaruoMlWBL3f1Id51urcUpShlESnOXQg8tNT+/kP\n"\
"hL7RN/kE3uOhKBXJ7TGKP/gvLcCgV5rDKE3kcSSx0VZ/a6T1+qY25r8FtCNFY0Yg\n"\
"XGMSQxZ1AEaMC45ZaKCHvFFzkELVDuxByHZJGvo6KukhdrSoOr1kAWka7yc7aMqi\n"\
"iMhn/vqoo9105NTlpDQ+oqrWH8Uo72A4+JGIrNUIWdiN+W3IF24LiZ08SqD3\n"	\
"-----END CERTIFICATE-----\n"

#define SERVER_KEY                                                       \
"-----BEGIN RSA PRIVATE KEY-----\n"								   	\
"MIIEpQIBAAKCAQEAn4Yred/xMoO4ND8TOYl4kjWlEO7qfzn9+QEACClGncOQoa4l\n"\
"tz4czcEkku3FtEmWyqTHgE0rUmKNp4uIGZGqV24ZCtAqNS6rhYGgTojxgV3P7ijl\n"\
"AGQkp/rUKAuWpXo29wBCvhy/5PqYBextuZxoSpfxhmTL4KGvitZ6nNJ72wm01zir\n"\
"M9pNOQ4yFh+dZJAUUk88vxWVaOc0k6Cjvw94REaePRA7h5jtuFu2BhQf1Bj04nZ3\n"\
"81B7xDApdKpf3FDqZCPCtUEjCxFsYnMO/LROOsg0/n9vluz0TJutJnOvnmlGCLFU\n"\
"Ls1tuPIVDPEHChepYwTL2rTOYTX7tk0VMEvFAwIDAQABAoIBAQCabLWVi3XgIqak\n"\
"3RJtNmjjkM6z77RNaQQ0kgVH4T0c5/4QpZaZJqWXgIs5OLeUaVBx5sXBq/JuFD1w\n"\
"naAosFwnusq/LvhM91rPKMbYf7TaOMhaknfswwTBIA1UnrM8iWy/+x6hDw+sR/H2\n"\
"egNWFNTYsPH72YOLdrmKO0oCmbeQNvPqk+icSCvnB2ehjc6m6Fcy6jwWygN7r1oX\n"\
"aHpBsF+nY9w59yzc3dlTlIsCnAxsyq3Zscw7/iuPXvQgjiLGtz/J+V7BsGqdDZM2\n"\
"jUCNvdsBD6EPXmF4YB358C7T6SZv5XMeqoZy8gkd1ChfXwOnhXkpziYD9ZgUNbt6\n"\
"zie1/99BAoGBAM2hXlcdK0tfHntjVdYIRcVKP13mYOBHDH/txNQv5hR9Cqhd9Kf3\n"\
"DKAB4MZNEAc0JBBVmYc+SpRbBpqL2GJmGXkUrV3WjQGhZRjqHTCDvI1HCypEFhXh\n"\
"WlTlVoudBuvtvsGljZs2oM/2VaQJRej+IS0RacIzrG+YUXQoWjpnlZGTAoGBAMaZ\n"\
"lDuJrNHFdONdLhewpVFZxtZ1D4nT8I2TgRv8Ihzp0VQJhyi6n8KruyRQCE4D1LrT\n"\
"MIqcG7QshQFr/KDmO61yIMnqKKhDO7YMjci8KwWQCNzLs1P7/QNKQaZLPiga/Eo/\n"\
"dj7d8ZK+pLZ4Q3D701xSm+8qRDY7YS+DQcO58+TRAoGBAKMaXyk8Es47CYOXfEtD\n"\
"zou5499IUAk1cd27LEeeIqKXuC9qLxhXpiT4uGCyWYdNPVnTe+7BYwif1vIZAK60\n"\
"C3p2AzmOZ9QmP3luoW6M368z7dA9p0L9t9fk/SvKhuX2cztIZLT7tLyfyLhPPqub\n"\
"f5cu27NVp23w5JL9Ouxeo02PAoGAB4uqQCDY+hdge4r8x1Wk0lRw45ELCBePWjGy\n"\
"hBeuTB7uHx1Fj1yX2VOhBp4r0pr+qCKCA6Iuw0e1vfoWXR6iQdLGQCWvacU0LZSI\n"\
"honvsIRqcckjhRtb35YgrGrLb8ams0N6AKV6GjM4Gt6y4UYQH7/bwNiAQvc6mA2K\n"\
"oB8ejyECgYEAwHWLnJ5624vSiv314kj70a+fHd8hBCjrGMGWoQWmiPF72t/Dx0ah\n"\
"Xk266s4LF5kcRY17nMNu6q49yh4bvg++4BWzYBOXoUPqRc7/lnJCDn+6Jzc0Mca5\n"\
"PGz5gvgOyER6TcazqjzyiVkCHnxmyIPo0WUh41Pl6WLwV+GmG/GbPhE=\n"		\
"-----END RSA PRIVATE KEY-----\n"


#endif /* INC_CERTS_H_ */
