use std::{fs::{File}, io::{BufRead, BufReader}};

/// Print help messages when program
/// would fail due to bad input
fn print_help() {
    let args: Vec<String> = std::env::args().collect();

    println!("usage: {} <target> <file/stream>", args[0]);
}

/// Grep arguments
#[derive(Debug)]
struct Args {
    pattern: String,
    file_name_or_stream: String,
}

impl Args {
    /// Wrapper for std::env::args
    fn read_from_stdenv() -> Vec<String> {
        let args: Vec<String> = std::env::args().collect();
        args
    }

    /// Parse std::env::args to Args struct
    fn parse(args: Vec<String>) -> Args {
        if args.len() != 3 {
            print_help();
        }

        let pattern = match args.get(1) {
            Some(v) => v.clone(),
            None => {
                print_help();
                std::process::exit(1);
            },
        };

        if [
            String::from("help"),
            String::from("--help"),
            String::from("-h")
        ].contains(&pattern) && args.len() == 2 {
            print_help();
            std::process::exit(0);
        }

        let file_name_or_stream = match args.get(2) {
            Some(v) => v.clone(),
            None => {
                print_help();
                std::process::exit(1);
            },
        };

        Args { pattern, file_name_or_stream }
    }
}

fn main() {
    let args = Args::parse(Args::read_from_stdenv());

    // TODO: Assuming Args.file_name_or_stream is a file name for now
    let file = match File::open(&args.file_name_or_stream) {
        Ok(file) => file,
        Err(_) => panic!("failed to read file {}", &args.file_name_or_stream),
    };

    let reader = BufReader::new(file);

    for line in reader.lines().filter_map(Result::ok) {
        if line.contains(&args.pattern) {
            println!("{}", line);
        }
    }
}

