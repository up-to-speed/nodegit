{
  "variables": {
    "variables": {
      "target%": "none",
    },
    "uses_bundled_openssl%": "<!(node ./utils/usesBundledOpenSSL.js <(node_root_dir))",
    "is_IBMi%": "<!(node -p \"os.platform() == 'aix' && os.type() == 'OS400' ? 1 : 0\")",
    "bundled_openssl_root%": "<!(node ./utils/getBundledOpenSSLRoot.js <(module_root_dir))",
    "bundled_openssl_static%": "<!(node -p \"process.platform !== 'linux' || process.env.NODEGIT_OPENSSL_STATIC_LINK === '1' ? 1 : 0\")",
    "cxx_version%": "<!(node ./utils/defaultCxxStandard.js <(target))",
    "has_cxxflags%": "<!(node -p \"process.env.CXXFLAGS ? 1 : 0\")",
    "macOS_deployment_target": "10.11",
    # https://github.com/nodejs/node-gyp/issues/2673
    'openssl_fips': '',
  },

  "targets": [
    {
      "target_name": "bungit",

      "dependencies": [
        "vendor/libgit2.gyp:libgit2"
      ],

      "variables": {
        "coverage%": 0
      },
      "sources": [
        "src/async_baton.cc",
        "src/async_worker.cc",
        "src/lock_master.cc",
        "src/reference_counter.cc",
        "src/thread_pool.cc",
        "src/bungit.cc",
        "src/init_ssh2.cc",
        "src/promise_completion.cc",
        "src/wrapper.cc",
        "src/functions/copy.cc",
        "src/functions/free.cc",
        "src/cleanup_handle.cc",
        "src/convenient_patch.cc",
        "src/convenient_hunk.cc",
        "src/filter_registry.cc",
        "src/git_buf_converter.cc",
        "src/str_array_converter.cc",
        "src/context.cc",
        "src/v8_helpers.cc",
        "src/tracker_wrap.cc",
        {% each %}
          {% if type != "enum" %}
            "src/{{ name }}.cc",
          {% endif %}
        {% endeach %}
      ],

      "include_dirs": [
        "vendor/libssh2/include",
        "<!(node -p \"require('node-addon-api').include_dir\")"
      ],

      "defines": [
        "NAPI_VERSION=8",
        "NODE_ADDON_API_DISABLE_DEPRECATED",
        "NAPI_CPP_EXCEPTIONS"
      ],

      "cflags": [
        "-Wall",
        "-fexceptions"
      ],

      "conditions": [
        [
          "coverage==1", {
            "cflags": [
              "-ftest-coverage",
              "-fprofile-arcs"
            ],
            "link_settings": {
              "libraries": [
                "-lgcov"
              ]
            },
          }
        ],
        [
          "OS=='mac'", {
            "libraries": [
              "-liconv",
            ],
            "conditions": [
              ["<(uses_bundled_openssl) == 1", {
                "include_dirs": [
                  "<(bundled_openssl_root)/include"
                ],
                "libraries": [
                  "<(bundled_openssl_root)/lib/libssl.a",
                  "<(bundled_openssl_root)/lib/libcrypto.a"
                ]
              }],
              ["<(uses_bundled_openssl) != 1", {
                "include_dirs": [
                  "<!(pkg-config --cflags-only-I openssl 2>/dev/null | sed 's/-I//g' || true)"
                ],
                "libraries": [
                  "<!@(pkg-config --libs openssl 2>/dev/null || echo '')"
                ]
              }]
            ],
            "xcode_settings": {
              "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
              "MACOSX_DEPLOYMENT_TARGET": "<(macOS_deployment_target)",
              'CLANG_CXX_LIBRARY': 'libc++',
              'CLANG_CXX_LANGUAGE_STANDARD':'c++<(cxx_version)',

              "WARNING_CFLAGS": [
                "-Wno-unused-variable",
                "-Wint-conversions",
                "-Wmissing-field-initializers",
                "-Wno-c++11-extensions"
              ]
            }
          }
        ],
        [
          "OS=='win'", {
            "include_dirs": ["<(bundled_openssl_root)/include"],
            "defines": [
              "_HAS_EXCEPTIONS=1",
              "NOMINMAX=1",
              "WIN32_LEAN_AND_MEAN=1"
            ],
            "msvs_settings": {
              "VCCLCompilerTool": {
                "AdditionalOptions": [
                  "/std:c++<(cxx_version)",
                  "/EHsc"
                ]
              },
              "VCLinkerTool": {
                "AdditionalDependencies": [
                  "<(bundled_openssl_root)/lib/libcrypto.lib",
                  "<(bundled_openssl_root)/lib/libssl.lib"
                ],
                "AdditionalOptions": [
                  "/FORCE:MULTIPLE"
                ]
              }
            },
            "libraries": [
              "crypt32.lib",
              "rpcrt4.lib",
              "secur32.lib"
            ]
          }
        ],
        ["OS=='mac' or OS=='linux' or OS.endswith('bsd') or <(is_IBMi) == 1", {
          "libraries": [
            "<!(krb5-config gssapi --libs)"
          ]
        }],
        ["OS=='linux' or OS.endswith('bsd') or <(is_IBMi) == 1", {
          "cflags_cc": [
            "-fexceptions"
          ],
          "conditions": [
            ["<(has_cxxflags) == 0", {
              "cflags_cc": [
                "-std=c++<(cxx_version)"
              ],
            }],
            ["<(uses_bundled_openssl) == 1", {
              "conditions": [
                ["<(bundled_openssl_static) == 1", {
                  "libraries": [
                    "<(bundled_openssl_root)/lib/libssl.a",
                    "<(bundled_openssl_root)/lib/libcrypto.a"
                  ]
                }],
                ["<(bundled_openssl_static) != 1", {
                  "library_dirs": [
                    "<(bundled_openssl_root)/lib"
                  ],
                  "libraries": [
                    "-lcrypto",
                    "-lssl"
                  ]
                }]
              ],
              "include_dirs": [
                "<(bundled_openssl_root)/include"
              ],
            }],
            ["<(uses_bundled_openssl) != 1", {
              "libraries": [
                "<!@(pkg-config --libs openssl 2>/dev/null || echo '-lcrypto -lssl')"
              ]
            }],
          ],
        }],
        [
          "<(is_IBMi) == 1", {
            "include_dirs": [
              "/QOpenSys/pkgs/include"
            ],
            "libraries": [
              "-L/QOpenSys/pkgs/lib"
            ]
          }
        ]
      ]
    }
  ]
}
